#include <string.h>
#include <stdio.h>
#include "ring.h"

static struct {
    int curr;
    char log[MAX_LOG_ENTRY][MAX_STRING_LENGTH];
} buff;

void init_buffer() {
    printf("Initialize the ring buffer\n");
    int i;
    for(i =0; i<MAX_LOG_ENTRY; i++) {
        buff.log[i][0]='\0';
    }
}

void log_msg(char *entry) {
    printf("Adding log entry into buffer\n");
    int idx = buff.curr % MAX_LOG_ENTRY;
    strncpy(buff.log[idx],entry,MAX_STRING_LENGTH);
    /*
     * From the documentation of strncpy:
     * No null-character is implicitly appended at the end of destination
     * if source is longer than num. Thus, in this case, destination shall
     * not be considered a null terminated C string
     * (reading it as such would overflow).
     *
     * Thus we need to make sure that we null terminate the string;
     */
    buff.log[idx][MAX_STRING_LENGTH-1]='\0';
    buff.curr++;
}


/*
 * Right now this is just printing to the console. We want to change this to
 * write to a file (log_name) and we want to use signals to trigger the logging
 * event
 *
 * This method should write all the current entries to disk. We will use
 * the constant log_name as the name of the file.
 */
static void dump_buffer() {
    int i;
    for(i =0; i<MAX_LOG_ENTRY; i++) {
        printf("log %d: %s\n",i, buff.log[i]);
    }
}
