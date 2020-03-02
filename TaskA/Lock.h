/*
 * Lock.h -- simple mutual exclusion lock based on posix pthreads lock
 */
#ifndef _LOCK_H_
#define  _LOCK_H_
#include <pthread.h>

struct Lock;

void init_lock(struct Lock* lock);
void free_lock(struct Lock* lock);
void acquire(struct Lock* lock);
void release(struct Lock* lock);
pthread_mutex_t* getRawLock(struct Lock* lock);

struct Lock{
    pthread_mutex_t lock;
    void (*acquire)(struct Lock*);
    void (*release)(struct Lock*);
    pthread_mutex_t* (*getRawLock)(struct Lock*); // CV needs this
};
#endif
