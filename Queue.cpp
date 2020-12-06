#include "utils.h"

Queue* createQueue(int capacity) { 

    Queue* queue = new Queue(); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0; 
  
    queue->rear = capacity - 1; 
    queue->arrayOfTeams = new Team[( 
        queue->capacity * sizeof(Team))]; 
    return queue; 
} 

Team deQueue(Queue* queue) { 

    if (isEmpty(queue)) {
        Team echipa = Team();
        return echipa; 
    }

    Team echipa = queue->arrayOfTeams[queue->front]; 
    queue->front = (queue->front + 1) 
                   % queue->capacity; 
    queue->size = queue->size - 1; 
    return echipa; 
} 

// Function to add an item to the queue. 
// It changes rear and size 
void enQueue(Queue* queue, Team echipa) { 

    if ( isFull(queue) ) {
        return; 
    }
    queue->rear = (queue->rear + 1) 
                  % queue->capacity; 
    queue->arrayOfTeams[queue->rear] = echipa; 
    queue->size = queue->size + 1; 
} 
  
// Queue is empty when size is 0 
// 1 daca este goala
// 0 daca nu e goala
int isEmpty(Queue* queue) { 
    return (queue->size == 0); 
} 

int isFull(Queue* queue) { 
    return (queue->size == queue->capacity); 
} 

Team front(Queue* queue) {  
    return queue->arrayOfTeams[queue->front]; 
} 
  
// Function to get rear of queue 
Team rear(Queue* queue) { 
    return queue->arrayOfTeams[queue->rear]; 
} 
 

  
