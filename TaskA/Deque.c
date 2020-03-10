#include "Deque.h"

// A utility function to create a new linked list node. 
struct QNode* newNode(struct Task* k) 
{ 
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode)); 
    temp->key = k; 
    temp->next = NULL; 
    temp->prev = NULL; 
    return temp; 
} 

struct Task* front(struct Deque* q)
{
    return q->frontn->key;
}

struct Task* back(struct Deque* q)
{
    return q->backn->key;
}
  
struct QNode* push(struct Deque* q, struct Task* k)
{
    // Create a new LL node 
    struct QNode* temp = newNode(k); 
  
    // If queue is empty, then new node is front and back both 
    if (q->backn == NULL) { 
        q->frontn = q->backn = temp; 
    } 
    return temp; 
}

// The function to add a key k to q 
void push_back(struct Deque* q, struct Task* k) 
{ 
    struct QNode* temp = push(q, k);
    // Add the new node at the end of queue and change back 
    q->backn->next = temp; 
    temp->prev = q->backn;
    q->backn = temp; 
} 

// The function to add a key k to q 
void push_front(struct Deque* q, struct Task* k) 
{ 
    struct QNode* temp = push(q, k);
  
    q->frontn->prev = temp;
    temp->next = q->frontn;
    q->frontn = temp; 
} 

  
// Function to remove a key from given queue q 
void pop_front(struct Deque* q) 
{ 
    // If queue is empty, return NULL. 
    if (q->frontn == NULL) 
        return; 
  
    // Store previous front and move front one node ahead 
    struct QNode* temp = q->frontn; 
  
    q->frontn = q->frontn->next; 
  
    // If front becomes NULL, then change back also as NULL 
    if (q->frontn == NULL) 
        q->backn = NULL; 
  
    free(temp); 
}

// Function to remove a key from given queue q 
void pop_back(struct Deque* q) 
{ 
    // If queue is empty, return NULL. 
    if (q->frontn == NULL) 
        return; 
  
    // Store previous front and move front one node ahead 
    struct QNode* temp = q->backn; 
  
    q->backn = q->backn->prev; 
  
    if (q->backn == NULL) 
        q->frontn = NULL; 
  
    free(temp);
}

int empty(struct Deque* q)
{
    return q->backn == NULL;
}

// A utility function to create an empty queue 
void init_deque(struct Deque* q) 
{ 
    q->frontn = q->backn = NULL; 
    q->front = front;
    q->back = back;
    q->push_back = push_back;
    q->push_front = push_front;
    q->pop_back = pop_back;
    q->pop_front = pop_front;
    q->empty = empty;
} 
  
