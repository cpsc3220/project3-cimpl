#include <assert.h>
#include <pthread.h>
#include "Lock.h"


void free_lock(struct Lock* lock)
{
  pthread_mutex_destroy(&lock->lock);
}

void acquire(struct Lock* lock)
{
  int err = pthread_mutex_lock(&lock->lock);
  assert(!err);
}

void release(struct Lock* lock)
{
  int err = pthread_mutex_unlock(&lock->lock);
  assert(!err);
}


// CV needs this protected function
pthread_mutex_t *
getRawLock(struct Lock* lock)
{
  return &lock->lock;
} 

void init_lock(struct Lock* lock)
{
  int err = pthread_mutex_init(&lock->lock, NULL);
  assert(!err);
  lock->acquire = acquire;
  lock->release = release;
  lock->getRawLock = getRawLock; // CV needs this
}
