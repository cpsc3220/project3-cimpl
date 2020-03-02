#include <assert.h>
#include <pthread.h>
#include "CV.h"
#include "Lock.h"

void init_cv(struct CV* cv)
{
    int err = pthread_cond_init(&cv->cond, NULL);
    assert(!err);
    cv->wait = wait;
    cv->signal = signal;
    cv->broadcast = broadcast;
}

free_cv(struct CV* cv)
{
    int err = pthread_cond_destroy(&cv->cond);
    assert(!err);
    cv->wait = NULL;
    cv->signal = NULL;
    cv->broadcast = NULL;
}

void wait(struct CV* cv, Lock *lock)
{
  int err = pthread_cond_wait(&cv->cond, lock->getRawLock());
  assert(!err);
}

void signal(struct CV* cv)
{
  int err = pthread_cond_signal(cv->cond);
  assert(!err);
}

void broadcast(struct CV* cv)
{
  int err = pthread_cond_broadcast(&cv->cond);
  assert(!err);
}
