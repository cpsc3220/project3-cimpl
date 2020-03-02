// A C program to demonstrate linked list based implementation of queue 
#include <stdio.h> 
#include <stdlib.h> 
  
#pragma once

// Borrowed queue impl from
// https://www.geeksforgeeks.org/queue-linked-list-implementation/

struct QNode;
struct Queue;

struct QNode* newNode(int k); 
struct Queue* createQueue(); 
void enQueue(struct Queue* q, int k); 
void deQueue(struct Queue* q); 

// A linked list (LL) node to store a queue entry 
struct QNode { 
    int key; 
    struct QNode* next; 
}; 
  
// The queue, front stores the front node of LL and rear stores the 
// last node of LL 
struct Queue { 
    struct QNode *front, *rear; 
}; 
  
