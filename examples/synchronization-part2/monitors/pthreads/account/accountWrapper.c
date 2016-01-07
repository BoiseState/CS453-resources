
/* 
 * A simple monitor example
 * 
 * Author: Amit Jain
 *
 */ 

 
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include "account.h"

static void __credit(AccountPtr acct, double amount);
static void __debit(AccountPtr acct, double amount); 


AccountPtr account_init()
{

	AccountPtr acct = (AccountPtr) malloc(sizeof(Account));
	acct->balance = 0.0;
	pthread_mutex_init(&(acct->mutex), NULL);
	return acct;
}

void credit(AccountPtr acct, double amount) 
{
	pthread_mutex_lock(&(acct->mutex));
	__credit(acct, amount);
	pthread_mutex_unlock(&(acct->mutex));
}

void debit(AccountPtr acct, double amount) 
{
	pthread_mutex_lock(&(acct->mutex));
	__debit(acct, amount);
	pthread_mutex_unlock(&(acct->mutex));
}

static void __credit(AccountPtr acct, double amount) 
{
	acct->balance += amount;
}

static void __debit(AccountPtr acct, double amount) 
{
	acct->balance -= amount;
}

/* vim: set ts=4: */
