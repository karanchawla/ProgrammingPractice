/*
Karan Chawla
Data Structure: Queue
FIFO
Operations: 
1. Enqueue 
2. Dequeue
3. Front
4. Rear
*/

//Array Implementation
#include "stdio.h"
#include "stdlib.h"
#include <limits.h>

struct Queue
{
	int front,rear,size;
	unsigned capacity;
	int* array;
};

//function to create a queue with given capacity
struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->array = (int*) malloc(queue->capacity*sizeof(int));
	queue->front = queue->size = 0;
	queue->rear = capacity - 1; //used for enqueue

	return queue;
}

//queue is full when size is capacity
int isFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}

//queue is empty when size is zero
int isEmpty(struct Queue* queue)
{
	return (queue->size==0);
}

//function to add item to the queue
void enqueue(struct Queue* queue, int new_item)
{
	if(isFull(queue))
		return;
	queue->rear = (queue->rear + 1)%queue->capacity;
	queue->array[queue->rear] = new_item;
	queue->size = queue->size + 1;
	printf("%d enqueued to queue\n", new_item);
}

//function to dequeue an item. changes front and size
int dequeue(struct Queue* queue)
{
	if(isEmpty(queue))
		return 0;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)%(queue->capacity);
	queue->size = queue->size - 1;
	return item;
}

//function to get an item from queue
int front(struct Queue* queue)
{
	if(isEmpty)
		return INT_MIN;
	return queue->array[queue->front];
}

//function to return last element from a queue
int rear(struct Queue* queue)
{
	if(isEmpty(queue))
		return INT_MAX;

	return queue->array[queue->rear];
}

//driver program
int main(void)
{
	struct Queue* queue = createQueue(1000);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
 	return 0;
}