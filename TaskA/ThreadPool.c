#include "ThreadPool.h"

void init_ThreadPool(struct ThreadPool* tp, unsigned int numThreads) {
    tp->threads = malloc(sizeof(thread_t) * (numThreads));
    assert(tp->threads != 0);
    tp->nThreads = numThreads;
    tp->stop = false;
    tp->shutdown = shutdown;
    tp->thread_work = thread_work;
    tp->submit = submit;
    for (int i = 0; i < tp->nThreads; i ++) {
        thread_create_p(&tp->threads[i], executor, (void*) tp);
    }
}

int submit(struct ThreadPool* tp, void (*task)(void *), void *p) {
    // PUT YOUR CODE HERE
   



     return 0;
}

void shutdown(struct ThreadPool* tp) {
    // PUT YOUR CODE HERE
}

void free_ThreadPool(struct ThreadPool* tp) {
    free(tp->threads);
}

void thread_work(struct ThreadPool* tp) {
    // PUT YOUR CODE HERE
}

void * executor(void *p) {
    struct ThreadPool *tp = (struct ThreadPool *)p;
    tp->thread_work(tp);

    thread_exit(0);
    return 0;
}
