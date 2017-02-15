#ifndef __RING_H
#define __RING_H

/* The maximum number of logs that our ring buffer will hold at any one time.*/
#define MAX_LOG_ENTRY 5

/*The maximum length of an individual log entry.*/
#define MAX_STRING_LENGTH 80

/*The name of the file that we will write our log to */
const char* log_name = "ring.log";

/*The number of seconds between dumps to disk*/
const int alarm_interval = 2;

/**
 * Initialize the buffer for use. 
 * We must call this function before calling log_msg to ensure 
 * all the memory has been allocated and is ready to use.
 *
 * @return none
 */
void init_buffer();

/**
 * Add entry into the ring buffer. 
 * We can assume that entry is a properly terminated string. 
 * However we can NOT assume that entry is less than MAX_STRING_LENGTH,
 * so we must be careful when copying our data.
 *
 * @param entry  null-terminated string that contains the log message
 * @return none
 */
void log_msg(char *entry);

#endif /* __RING_H */
