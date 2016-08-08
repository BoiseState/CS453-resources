
#ifndef __ACCOUNT_H
#define __ACCOUNT_H

/** 
 * A simple monitor example that uses a mutex to protect against race conditions.
 * 
 * @author: amit
 */ 

#include <pthread.h>

#define TRUE 1
#define FALSE 0

typedef struct account Account;
typedef struct account *AccountPtr;

struct account {
	double balance;
	pthread_mutex_t mutex;
};


/**
 * Constructor: creates a new account wuth zero balance and an associated mutex lock.
 */
AccountPtr account_init();


/**
 * Credit the specified amount to the account.
 * @param acct The account to use.
 * @param amount The amount to credit.
 */
void credit(AccountPtr acct, double amount);


/**
 * debit the specified amount from the account.
 * @param acct The account to use.
 * @param amount The amount to debit.
 */
void debit(AccountPtr acct, double amount);

#endif /* __ACCOUNT_H */

/* vim: set ts=4: */

