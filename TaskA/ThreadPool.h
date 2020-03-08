#ifndef PROJECT3_THREADPOOL_H
#define PROJECT3_THREADPOOL_H

#include <stddef.h>
#include <stdbool.h>
#include "thread.h"
#include "Lock.h"
#include "CV.h"
#include "Deque.h"
#include <assert.h>

void * executor(void *p);


struct ThreadPool;

void init_ThreadPool(struct ThreadPool*, unsigned int numThreads);
void free_ThreadPool(struct ThreadPool*);
int submit(struct ThreadPool* tp, void (*task)(void *), void *p);
void shutdown(struct ThreadPool* tp);
void thread_work(struct ThreadPool* tp);
void * executor(void *p);


struct ThreadPool {
    int (*submit)(struct ThreadPool*, void (*task)(void *), void *p);
    void (*shutdown)(struct ThreadPool*);
    void (*thread_work)(struct ThreadPool*);

    // You can add your synchronization variables here
    //
    thread_t *threads;
    int nThreads;
    bool stop;
    struct Deque queue;
};
#endif //PROJECT3_THREADPOOL_H
