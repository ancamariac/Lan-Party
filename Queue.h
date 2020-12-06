#ifndef QUEUE_H
#define QUEUE_H
#include "Team.h"
using namespace std;

class Queue {
    public:
        Team *arrayOfTeams;       // array to store teams 
        int capacity;   // maximum capacity of the queue
        int front;      // front points to front element in the queue (if any)
        int rear;       // rear points to last element in the queue
        int size;      // current size of the queue
}; 

Queue* createQueue(int capac);     

Team deQueue(Queue* queue);
void enQueue(Queue* queue, Team t);
int isEmpty(Queue* queue);
int isFull(Queue* queue);
Team front(Queue* queue);
Team rear(Queue* queue);

#endif