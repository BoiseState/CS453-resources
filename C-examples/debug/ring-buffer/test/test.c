#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //for sleep ()
//This is an example of using a relative path to import header files.
//Generally you would want to use the -I flag in the compiler to set
//up the include paths. Using relative paths like this creates a
//dependency on the file structure which could make it tough to move
//this file around.
#include "../include/ring.h"

int main(void) {

    init_buffer();
    /*Add in a bunch of entries*/
    log_msg("Info: start-up");
    log_msg("Warning: Foo has occurred");
    log_msg("Error: failed 1");
    log_msg("Error: failed 2");
    log_msg("Error: failed 3");
    log_msg("Error: failed 4");
    log_msg("Error: failed 5");
    /*Test a message that is too long, we should not corrupt memory */
    log_msg("Error: we tried to make foo when we needed bar  ... oops that was a pretty crazy thing to do");
    log_msg("Error: failed 6");
    log_msg("Error: shutdown");

    //sleep for (alarm_interval + 1) seconds to ensure that the
    //signal has fired and we have written out our file
    //This approach (hard coded sleep) is really bad
    //however for a quick test we can live with it for now
    printf("Sleeping for %d seconds to let signals finish\n" , alarm_interval +1);
    sleep(alarm_interval +1);
    exit(EXIT_SUCCESS);
}
