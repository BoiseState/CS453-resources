#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //for sleep ()
#include <ring.h>

int main(void)
{

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
    log_msg("Error: shutdown 1");
    log_msg("Error: shutdown 2");
    log_msg("Error: shutdown 3");

    //sleep for (alarm_interval + 1) seconds to ensure that the
    //signal has fired and we have written out our file
    //This approach (hard coded sleep) is really bad
    //however for a quick test we can live with it for now
    printf("Sleeping for %d seconds to let signals finish\n" , alarm_interval + 2);
    sleep(alarm_interval + 2);
    exit(EXIT_SUCCESS);
}
