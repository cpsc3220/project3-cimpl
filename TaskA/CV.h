/*
 * CV.h -- simple condition variable based on pthreads
 */
#ifndef _CV_H_
#define _CV_H_
#include <pthread.h>
#include "Lock.h"

struct CV;

void init_cv(struct CV*);
void free_cv(struct CV*);
void wait(struct CV* cv, struct Lock *lock);
void signal(struct CV* cv);
void broadcast(struct CV* cv);

struct CV
{
  pthread_cond_t cond;
  void (*wait)(struct CV*, struct Lock *lock);
  void (*signal)(struct CV* );
  void (*broadcast)(struct CV*);
};

#endif
