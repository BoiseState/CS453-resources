#include	<sys/types.h>
#include	<sys/stat.h>
#include	<dirent.h>
#include	<limits.h>
#include	"ourhdr.h"

typedef	int	Myfunc(const char *, const struct stat *, int);
				/* function type that's called for each filename */

static Myfunc	myfunc;
static int		myftw(char *, Myfunc *);
static int		dopath(Myfunc *);
char *path_alloc(int *size);


#define HISTOGRAM_SIZE 1000
static int histogram[HISTOGRAM_SIZE+1];

int main(int argc, char *argv[])
{
	int		ret;
	int 	i;

	if (argc != 2)
		err_quit("usage:  %s  <starting-pathname>", argv[0]);

	for (i=0; i<= HISTOGRAM_SIZE; i++)
			histogram[i]=0;
	ret = myftw(argv[1], myfunc);		/* does it all */

	printf("#  size(KB) num \n");
	for (i=0; i< HISTOGRAM_SIZE; i++)
			printf(" %d %d \n", i, histogram[i]);
	printf(" > 1000KB %d \n", histogram[i]);

	ret = myftw(argv[1], myfunc);		/* does it all */


	exit(ret);
}

/*
 * Descend through the hierarchy, starting at "pathname".
 * The caller's func() is called for every file.
 */

#define	FTW_F	1		/* file other than directory */
#define	FTW_D	2		/* directory */
#define	FTW_DNR	3		/* directory that can't be read */
#define	FTW_NS	4		/* file that we can't stat */

static char	*fullpath;		/* contains full pathname for every file */

/* we return whatever func() returns */
static int myftw(char *pathname, Myfunc *func)
{
	fullpath = path_alloc(NULL);	/* malloc's for PATH_MAX+1 bytes */
									/* ({Prog pathalloc}) */
	strcpy(fullpath, pathname);		/* initialize fullpath */

	return(dopath(func));
}

/*
 * Descend through the hierarchy, starting at "fullpath".
 * If "fullpath" is anything other than a directory, we lstat() it,
 * call func(), and return.  For a directory, we call ourself
 * recursively for each name in the directory.
 */
static int dopath(Myfunc* func)
{
	struct stat		statbuf;
	struct dirent	*dirp;
	DIR				*dp;
	int				ret;
	char			*ptr;

	if (lstat(fullpath, &statbuf) < 0)
		return(func(fullpath, &statbuf, FTW_NS));	/* stat error */

	if (S_ISDIR(statbuf.st_mode) == 0)
		return(func(fullpath, &statbuf, FTW_F));	/* not a directory */

	/*
	 * It's a directory.  First call func() for the directory,
	 * then process each filename in the directory.
	 */

	if ( (ret = func(fullpath, &statbuf, FTW_D)) != 0)
		return(ret);

	ptr = fullpath + strlen(fullpath);	/* point to end of fullpath */
	*ptr++ = '/';
	*ptr = 0;

	if ( (dp = opendir(fullpath)) == NULL)
		return(func(fullpath, &statbuf, FTW_DNR));
										/* can't read directory */

	while ( (dirp = readdir(dp)) != NULL) {
		if (strcmp(dirp->d_name, ".") == 0  ||
		    strcmp(dirp->d_name, "..") == 0)
				continue;		/* ignore dot and dot-dot */

		strcpy(ptr, dirp->d_name);	/* append name after slash */

		if ( (ret = dopath(func)) != 0)		/* recursive */
			break;	/* time to leave */
	}
	ptr[-1] = 0;	/* erase everything from slash onwards */

	if (closedir(dp) < 0)
		err_ret("can't close directory %s", fullpath);

	return(ret);
}

static int myfunc(const char *pathname, const struct stat *statptr, int type)
{
	int bin;

	bin = statptr->st_size/1024; //size in KBs
	if (bin > HISTOGRAM_SIZE-1)
			bin = 1000;
	histogram[bin]++;

	return(0);
}
