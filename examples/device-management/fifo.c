
/*
--------- A Linux module that implements 4 FIFOs.
           
The simplest test is

echo baz > /dev/foo0
cat /dev/foo1

The second command should print "baz" (and a newline). A slightly more
complex test could be

echo -n baz > /dev/foo0
echo -n bletch > /dev/foo0
echo mumble > /dev/foo2
cat /dev/foo1
cat /dev/foo3

The first "cat" should print "bazbletch" (and no newline).

cat somelargefile > /dev/foo0 &
cat /dev/foo1 > tempfile
ls -l somelargefile tempfile
diff somelargefile tempfile

should show that the two files are identical. Note the ampersand: the
point here is to cause the writer to block.

------------------------------------------------------------------------------
*/

#define FIFO_NAME "assign9"
#define NUM_FIFOS (4)
#define FIFO_LEN (10) /* Small for purposes of easy test */
#define FIFO_MAJOR (42) /* bigger than anything in linux/major.h */

#include <linux/fs.h>
#include <linux/module.h>
#include <linux/version.h>
#include <errno.h>

#define TRUE (1)
#define FALSE (0)
typedef int boolean;

char kernel_version[]= UTS_RELEASE;

/**********************************************************************/

typedef struct { /* Simple wraparound fifo. */
			char data[ FIFO_LEN ];
			int head, tail;
			int contents; /* Count of valid data. */
} queue;

typedef struct {
			queue q;
			boolean read_is_open, write_is_open;
			struct wait_queue *wait_while_full;
			struct wait_queue *wait_while_empty;
} fifo;

fifo fifos[NUM_FIFOS];

/**********************************************************************
*
* Put char in a queue.
* Expects q is not full.
*/

static void push_char( queue *q, char ch )
{
	q->data[ q->tail++ ] = ch;
	if( q->tail >= FIFO_LEN ) q->tail = 0; /* wrap */

	q->contents++;
}

/**********************************************************************
*
* Get char from a queue.
* Expects q is not empty.
*/

static int pull_char( queue *q )
{
	int ch = q->data[ q->head++ ];
	if( q->head >= FIFO_LEN ) q->head = 0; /* wrap */

	q->contents--;
	return ch;
}

/**********************************************************************
*
* Read a char from the i'th fifo (which is open for read).
* May sleep, but will eventually succeed, or else return 0 (EOF).
* Returns EOF only if fifo is empty, and the fifo is not open by a writer.
*/

static int read_char( int i )
{
	int ch;
	if( (fifos[i].write_is_open == FALSE) && (fifos[i].q.contents == 0)) {
		return 0;
	}

	while( fifos[i].q.contents == 0 ) { /* while empty */

		/* if the writer is sleeping, wake him up */
		wake_up_interruptible( &fifos[i].wait_while_full );

		interruptible_sleep_on( &fifos[i].wait_while_empty );
	}
	/* It's not empty. */

	ch = pull_char( &fifos[i].q );
	return ch; /* NOTE: not only return stmt */
}

/**********************************************************************/
/**********************************************************************
*
* Write ch into the i'th fifo (which is open for write).
* May sleep, but will eventually succeed.
*/

static void write_char(int i, char ch)
{
	while( fifos[i].q.contents == FIFO_LEN ) { /* while full */

		/* if the reader is sleeping, wake him up */
		wake_up_interruptible( &fifos[i].wait_while_empty );

		interruptible_sleep_on( &fifos[i].wait_while_full );
	}

	/* It's not full. */
	push_char( &fifos[i].q, ch );
}

/**********************************************************************/
static int fifo_write(struct inode *inode, struct file *file,
						char *buf, int count)
{
	int cnt;
	unsigned int minor = MINOR(inode->i_rdev);
	int index = minor >> 1;
	int is_read = minor & 1;

	if( is_read )
		return -EIO; /* Can't write to a read fifo. */

	/* Assume that write is only callable if the open succeeded. */
	for( cnt = count; cnt > 0; cnt-- )
		write_char( index, get_fs_byte(buf++));

	return count;
}

/**********************************************************************/
static int fifo_open(struct inode *inode, struct file *file)
{
	unsigned int minor = MINOR(inode->i_rdev);
	int index = minor >> 1;
	int is_read = minor & 1;

	if( minor >= (2*NUM_FIFOS))
		return -ENODEV; /* Invalid minor number. */

	if( (!is_read) && (file->f_mode != 2 )) /* Read to a write fifo? */
		return -EPERM;

	if( is_read && (file->f_mode != 1 )) /* Write a read fifo? */
		return -EPERM;

	/* The request is valid per-se. Can we honor it? */

	if( is_read ) {
		if( fifos[index].read_is_open )
				return -EBUSY;
		fifos[index].read_is_open = TRUE;
	} else {
		if( fifos[index].write_is_open )
			return -EBUSY;
		fifos[index].write_is_open = TRUE;
	}

	MOD_INC_USE_COUNT; /* The module is now busy[er]. */
	return 0;
}

/**********************************************************************/
static void fifo_release(struct inode *inode, struct file *file)
{
	unsigned int minor = MINOR(inode->i_rdev);
	int index = minor >> 1;
	int is_read = minor & 1;

	/* Assume that release is only callable if the open succeeded. */
	if( is_read ) {
		fifos[index].read_is_open = FALSE;

		/* if the writer is sleeping, wake him up */
		wake_up_interruptible( &fifos[index].wait_while_full );
	} else {
		fifos[index].write_is_open = FALSE;

		/* if the reader is sleeping, wake him up */
		wake_up_interruptible( &fifos[index].wait_while_empty );
	}

	MOD_DEC_USE_COUNT;
}

/**********************************************************************/
static struct file_operations fifo_fops = {
		NULL, /* seek */
		fifo_read,
		fifo_write,
		NULL, /* readdir */
		NULL, /* select */
		NULL, /* ioctl */
		NULL, /* mmap */
		fifo_open,
		fifo_release
};

/**********************************************************************
*
* init_module and cleanup_module are the only non-static routines.
*/
int init_module(void)
{
	int i;

	if (register_chrdev(FIFO_MAJOR, FIFO_NAME, &fifo_fops)) {
		printk("unable to get major %d \n", FIFO_MAJOR );
		return -EIO;
	}

	/* Init the module's internal data. */
	for( i = 0; i < NUM_FIFOS; i++ ) {
		fifos[i].q.head = 0;
		fifos[i].q.tail = 0;
		fifos[i].q.contents = 0;

		fifos[i].read_is_open = FALSE;
		fifos[i].write_is_open = FALSE;
	
		fifos[i].wait_while_full = NULL;
		fifos[i].wait_while_empty = NULL;
	}
	return 0;
}

void cleanup_module(void)
{
	if( MOD_IN_USE )
		printk("%s: busy - remove delayed\n", FIFO_NAME);
	else
		if( unregister_chrdev( FIFO_MAJOR, FIFO_NAME ))
			printk( "%s: cleanup_module failure\n", FIFO_NAME);
}
