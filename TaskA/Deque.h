// A C program to demonstrate linked list based implementation of queue 
#include <stdio.h> 
#include <stdlib.h> 
  
#pragma once

struct Task {
    void (*func)(void *);
    void *param;
};


// Borrowed queue impl from
// https://www.geeksforgeeks.org/queue-linked-list-implementation/
// modified to look like C++ stl double-ended queue, sort of

struct Deque;

// A linked list (LL) node to store a queue entry 
struct QNode { 
    struct Task* key; 
    struct QNode* next; 
    struct QNode* prev;     
}; 
  
void init_deque (struct Deque* q); 

// The queue, front stores the front node of LL and rear stores the 
// last node of LL 
struct Deque { 
    struct QNode *frontn, *backn; 
    struct Task* (*front)(struct Deque* q); 
    struct Task* (*back)(struct Deque* q); 
    void (*push_front)(struct Deque* q, struct Task*); 
    void (*push_back)(struct Deque* q, struct Task*); 
    void (*pop_back)(struct Deque* q); 
    void (*pop_front)(struct Deque* q); 
    int (*empty)(struct Deque* q);
}; 
  
