
/**
 * Implementation of a  simple monitor example that uses a mutex to protect against race conditions.
 *
 * @author amit
 */


#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <Account.h>


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
    acct->balance += amount;
    pthread_mutex_unlock(&(acct->mutex));
}

void debit(AccountPtr acct, double amount)
{
    pthread_mutex_lock(&(acct->mutex));
    acct->balance -= amount;
    pthread_mutex_unlock(&(acct->mutex));
}

/* vim: set ts=4: */
