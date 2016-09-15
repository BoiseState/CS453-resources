/* public global defines */
#define MAX_CALLS 5 
#define SLEEP_TIME 3 

/* public global variable definition. no memory set aside.
 * Keeps track of the number of incoming calls. */
extern int total_calls;

/**
 * @brief Calls the phone and reads the provided message.
 *
 * @param message
 */
void call(const char *message, const int id);
