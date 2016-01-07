
#ifndef __ACCOUNT_H
#define __ACCOUNT_H

/* 
 * A simple monitor example
 * 
 * Author: Amit Jain
 *
 */ 

#include <pthread.h>

#define TRUE 1
#define FALSE 0

typedef struct account Account;
typedef struct account * AccountPtr;


struct account {
	double balance;
	pthread_mutex_t mutex;
};


AccountPtr account_init();

void credit(AccountPtr acct, double amount);
void debit(AccountPtr acct, double amount);

#endif /* __ACCOUNT_H */
/* vim: set ts=4: */

