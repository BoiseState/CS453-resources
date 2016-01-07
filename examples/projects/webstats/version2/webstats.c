

 /* webtstats.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

typedef int bool;
#define TRUE 1
#define FALSE 0
  

/*
	Generate some web statistics  based on access logs from the Apache web server. 
	In particular, this program looks for local versus total get requests. 
	It also analyzes failed gets and total bytes transferred.

	The format of a Apache web server access log is as follows:

	For a successful get:

	1cust107.tnt5.phoenix.az.da.uu.net - - [13/Mar/2001:15:45:45 -0700] 
                                             "GET /gas/gif/lib.gif HTTP/1.1" 200 1138

	The last field tells the number of bytes that were transferred. The second
	last field tells the status of the request: in this case 200 says it was 
	successful. A value of 404 implies that the object requested was not
	found.

	For an unsuccessful get:

	j3009.inktomi.com - - [11/Mar/2001:04:07:31 -0700] "GET /~kani HTTP/1.0" 404 278

	Using the webstats program: The following show various ways of invoking the
	webstat  program.

		webstats access_log

		webstats access_log.1 access_log.2

		webstats access_log.* 

	checkpointing support:
		Currently checkpoint support only works if webstat was invoked with
		one logfile. Extending to multiple files is not difficult.

	author: Amit Jain
*/

#define MAX_LINE_SIZE 4096
#define MAX_NUM_FIELDS 40

static void savestate(int);
static void print_webstats();

struct stats {
	double local_bytes;
	double total_bytes;
	double local_gets;
	double total_gets;
	double failed_gets;
	double local_failed_gets;
} webstats;

char *program_name;
char *checkpoint_file = "webstats.data";
char *current_logfile;
long filepos = 0;
char *linebuffer;
const int CHECKPOINT_INTERVAL=1; //1 seconds for demo purposes

static void manipulate_alarm_signal(char *);
void	err_dump(const char *, ...);	/* {App misc_source} */
void	err_msg(const char *, ...);
void	err_quit(const char *, ...);
void	err_ret(const char *, ...);
void	err_sys(const char *, ...);
const bool debug = FALSE;



/*
 * parse_line(): Parse one line into string tokens separated by the given delimiters.
 * Beware: The input argument line is consumed in the process.
 *
 *	input:
 * 		line: A character array containing the current server log entry line
 * 		delim: A character array containing the delimiters to be used to separate fields in the line
 *
 * 	output:
 * 		field: An array of strings that represent the tokens found in the line.
 *
 * 	return:
 * 		num: The number of tokens found in the line.
 */

static int parse_line(char *line, const char *delim, char *field[])
{
	char *next;
	int cnt=0;
	
	next = strtok(line, delim);
	while (next) {
		if (cnt == MAX_NUM_FIELDS-1) break;
		field[cnt] = (char *) malloc(strlen(next)+1);
		strcpy(field[cnt++],next);
		next =strtok(NULL, delim);
	}
	field[cnt] = (char *) 0; /* make the field array be null-terminated */

	return cnt;
}


/*
 * free_tokens(): Frees spaces allocated for tokens in parse_line
 *
 *	input:
 *	    field: an array of strings
 * 		num: An int representing number of tokens in array of strings named * 		field.
 *
 * 	output:
 *
 * 	return:
 * 		none.
 */

static void free_tokens(int num, char *field[])
{
	int i;

	for (i=0; i<num; i++)
		free(field[i]);
}


/*
 * initialize_webstats(): Initialize the webstats structure and setup alarm handler.
 *
 * 	input:	
 * 		none
 *	output
 * 		none
 * 	return
 * 		none
 */

static void initialize_webstats()
{
	webstats.total_bytes = 0;
	webstats.total_gets = 0;
	webstats.local_bytes = 0;
	webstats.local_gets = 0;
	webstats.failed_gets = 0;
	webstats.local_failed_gets = 0;

	signal(SIGALRM, savestate);
	/* set this later, after checking for checkpoint file */
	/*alarm(CHECKPOINT_INTERVAL); */

}



/*
 * start_from_checkpoint(): Check if we need to start from a checkpoint
 *
 * return
 * 		boolean: true if checkpoint will be used, false otherwise
 */
static bool start_from_checkpoint()
{	
	struct stat statbuf;
	/* see if there is a checkpoint file in current directory */
	if (stat(checkpoint_file, &statbuf) != -1)
	{
		time_t checkpoint_time = statbuf.st_ctime;
		char *time = ctime(&checkpoint_time);
		fprintf(stderr, "%s: found previous checkpoint file from %s",program_name, time);
		FILE *fp = fopen(checkpoint_file,"r");
		if (fp == NULL)
		{
			fprintf(stderr,"%s: aieee! Can't open checkpoint file: %s\n",program_name, 
																		checkpoint_file);
			exit(1);
		}
		int size = statbuf.st_size; /* size of file in bytes */
		char buffer[MAX_LINE_SIZE];
		fread(buffer, sizeof(char), (size - sizeof(struct stats) -sizeof(long)), fp);
		fprintf(stderr,"%s: logfile name from checkpoint_file: %s\n",program_name, buffer);
		if (strcmp(current_logfile, buffer) == 0)
		{
			fprintf(stderr, "%s: starting from checkpoint for logfile %s\n", 
													program_name, current_logfile);
			fread(&webstats, sizeof(struct stats), 1, fp);
			fread(&filepos, sizeof(long), 1, fp);
			fprintf(stderr, "%s: saved stats from checkpoint file\n",program_name); 
			print_webstats();
			return TRUE;
		} else {
			fprintf(stderr, "%s: current logfile does not match name in checkpoint file\n",
							program_name);
		}
		fclose(fp);
	}
	return FALSE;
}

/*
 *	update_webstats(): Updates the webstats structure based on the input fields of current line.
 *
 *	input: 
 *		num: The number of fields in the current webserver log entry
 *		field: An array of num strings representing the log entry
 *
 *	return: 
 *		none
 */
#define BYTES_DOWNLOADED_FIELD 9
#define HTTP_STATUS_CODE_FIELD 8
static void update_webstats(int num, char **field)
{
	int bytes_downloaded = atoi(field[BYTES_DOWNLOADED_FIELD]);

	webstats.total_gets++;
	webstats.total_bytes += bytes_downloaded;
	if (atoi(field[HTTP_STATUS_CODE_FIELD]) == 404) webstats.failed_gets++;

	if ((strstr(field[0], "boisestate.edu") != NULL) || (strstr(field[0], "132.178") != NULL))
	{
		webstats.local_gets++;
		webstats.local_bytes += bytes_downloaded;
		if (atoi(field[HTTP_STATUS_CODE_FIELD]) == 404)
			webstats.local_failed_gets++;
	}
}



/*
 * 	print_webstats(): Print out webstats on standard output.
 *
 *	input: 
 *		none
 *	output: 
 *		none
 *
 *	return
 *		none
 */

static void print_webstats()
{
	printf("%10s %15s   %15s  %15s\n", "TYPE", "gets","failed gets",
													"MB transferred");
	printf("%10s  %15.0f  %15.0f  %15.0f\n", "local", webstats.local_gets, 
		webstats.local_failed_gets, (double) webstats.local_bytes/(1024*1024));
	printf("%10s  %15.0f  %15.0f  %15.0f\n", "total", webstats.total_gets, 
		webstats.failed_gets, (double) webstats.total_bytes/(1024*1024));
}



/*
 * process_file(): The main function that processes one log file
 *
 *	input:
 * 		ptr: Pointer to log file name.
 *
 *	output:
 *		none
 *	return
 *		none
 */
static void process_file(void *ptr)
{
	bool flag;
	char *filename = (char *) ptr;
	char **field = (char **) malloc(sizeof(char *) * MAX_NUM_FIELDS);
	linebuffer = (char *) malloc(sizeof(char) * MAX_LINE_SIZE);
	char *end_date =  (char *) malloc(sizeof(char) * MAX_LINE_SIZE);

	FILE *fin = fopen(filename,"r");
	if (fin == NULL)
	{
		fprintf(stderr,"Cannot open file %s\n", filename);
		exit(1);
	}
	if (start_from_checkpoint())
	{
		char *s = fgets(linebuffer, MAX_LINE_SIZE, fin);
		if (s == NULL) return;
		int num = parse_line(linebuffer, " []\"", field);
		printf("Starting date: %s\n",field[3]);
		free_tokens(num, field);
		fseek(fin, filepos, SEEK_SET);
	} 
	else
	{
		fprintf(stderr,"%s: processing log file %s\n", program_name, filename);
		char *s = fgets(linebuffer, MAX_LINE_SIZE, fin);
		if (s == NULL) return;
		filepos += strlen(linebuffer);
		int num = parse_line(linebuffer, " []\"", field);
		update_webstats(num, field);
		printf("Starting date: %s\n",field[3]);
		free_tokens(num, field);
	}


	flag = TRUE;
	alarm(CHECKPOINT_INTERVAL);
	while (flag) 
	{
		/* block alarm signal */
		manipulate_alarm_signal("block");	
		char * status = fgets(linebuffer, MAX_LINE_SIZE, fin); 
		if (status == NULL) {
				flag = FALSE;
				break;
		} 
		filepos += strlen(linebuffer);
		int num = parse_line(linebuffer, " []\"", field);
		update_webstats(num, field);
		strcpy(end_date, field[3]);
		free_tokens(num, field);
		/* unblock and receive alarm signal now after updating */
		manipulate_alarm_signal("unblock");	

		strcpy(linebuffer,"");
	}
	printf("Ending date: %s\n",end_date);
	free(end_date);
}


/*
 * Helper function to block/unblock alarm signal
 *
 * input:	
 * 		char *todo:  "block" or "unblock"
 * return:
 * 		none
 */
static void manipulate_alarm_signal(char * todo)
{
	static sigset_t newmask, oldmask, pendmask;

	if (strcmp(todo, "block") == 0)
	{
		sigemptyset(&newmask);
		sigaddset(&newmask, SIGALRM);
		if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
			err_sys("Error in blocking signals\n");
	} 
	else if (strcmp(todo, "unblock") == 0) 
	{
		if (sigpending(&pendmask) < 0)
			err_sys("sigpending error");
		if (sigismember(&pendmask, SIGALRM))
		{
			if (debug) 
				fprintf(stderr,"\n Signal SIGALRM is pending\n");
		}

		if (sigprocmask(SIG_UNBLOCK, &newmask, &oldmask) < 0)
			err_sys("Error in unblocking signals\n");

	   /* better to restore the old mask, since the signal might be already blocked before 
          here (if this code was part of a function that can be called from various places)
	 	*/
	 	 if (sigprocmask(SIG_SETMASK, &oldmask, NULL) <0)
    	 	err_sys("Error in setting old signal mask\n");
	}
}



int main(int argc, char **argv)
{
	int i;

	if (argc <  2) {
		fprintf(stderr,"Usage: %s <access_log_file> {<access_log_file>} \n",argv[0]);
		exit(1);
	}

	program_name = (char *) malloc(strlen(argv[0])+1);
	strcpy(program_name, argv[0]);

	initialize_webstats();

	/* process the files specified on the command line */
	for (i=1; i<argc; i++)
	{
		current_logfile = (char *)malloc(strlen(argv[i])+1);
		strcpy(current_logfile, argv[i]);
		process_file(argv[i]);
	}

	print_webstats();

	/* remove checkpoint file */
	remove(checkpoint_file);

	exit(0);

}



/*
 * The signal handler that checkpoints the state of the program.
 *
 * input:
 * 		int signo: the signal that was caught
 * output: 
 * 		none
 */
static void savestate(int signo)
{
	FILE *fout;

	/* re-establish the signal handler for next time*/
	signal(SIGALRM, savestate);
	alarm(CHECKPOINT_INTERVAL);

	switch (signo)
	{
		case SIGALRM:
			fout = fopen(checkpoint_file,"w");
			if (fout == NULL)
			{
				fprintf(stderr,"Aieee! Can't open checkpoint file: %s\n",checkpoint_file);
				exit(1);
			}
			fwrite(current_logfile, sizeof(char), strlen(current_logfile)+1, fout);
			fwrite(&webstats, sizeof(struct stats), 1, fout);
			fwrite(&filepos, sizeof(long), 1, fout);
			fclose(fout);
			break;
		default:
			break;
	}
}

/* vim: set ts=4: */
