
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

/**
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
	webstats  program.

		webstats access_log

		webstats access_log.1 access_log.2

		webstats access_log.* 

	@author:  CS 453/552
*/

#define MAX_LINE_SIZE 4096
#define MAX_NUM_FIELDS 40


struct stats {
	double local_bytes;
	double total_bytes;
	double local_gets;
	double total_gets;
	double failed_gets;
	double local_failed_gets;
	char **url;
	int *requests;
} webstats;

char *program_name;

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
 * initialize_webstats(): Initialize the webstats structure.
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
}


/*
 *	update_webstats(): Updates the webstats structure based on the input fields of current line.
 *
 *	input: 
 *		num: The number of fields in the current webserver log entry
 *		field: An array of num strings representing the log entry
 *
 *	output: 
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
void process_file(void *ptr)
{
	char *filename = (char *) ptr;
	char *linebuffer = (char *) malloc(sizeof(char) * MAX_LINE_SIZE);
	char **field = (char **) malloc(sizeof(char *) * MAX_NUM_FIELDS);
	char *end_date = (char *) malloc(sizeof(char) * MAX_LINE_SIZE);

	fprintf(stderr,"%s: processing log file %s\n", program_name, filename);
	FILE *fin = fopen(filename,"r");
	if (fin == NULL)
	{
		fprintf(stderr,"Cannot open file %s\n", filename);
		exit(1);
	}
	char *s = fgets(linebuffer, MAX_LINE_SIZE, fin);
	if (s != NULL)
	{
		int num = parse_line(linebuffer, " []\"", field);
		update_webstats(num, field);
		printf("Starting date: %s\n",field[3]);
		free_tokens(num, field);

		while (fgets(linebuffer, MAX_LINE_SIZE, fin) != NULL)
		{
			int num = parse_line(linebuffer, " []\"", field);
			strcpy(end_date, field[3]);
			update_webstats(num, field);
			free_tokens(num, field);
			strcpy(linebuffer,"");
		}
		printf("Ending date: %s\n", end_date);
		free(end_date);
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

	for (i=1; i<argc; i++)
	{
		/*process the ith file*/
		process_file(argv[i]);
	}

	print_webstats();
	exit(0);

}

/* vim: set ts=4: */
