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

//Linked List Implementation

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

 
typedef struct queueNode {
	int data;
	struct queueNode *next;
}Node;


typedef struct queue {
	Node *front, *rear;
}Queue;

 
Queue *createQueue(unsigned capacity) {
	Queue *queue = (Queue *) malloc(sizeof(Queue));
	queue->front = queue->rear = NULL;
	return queue;
}
 
Node *createQueueNode(int data) {
	Node *node = (Node *) malloc(sizeof(Node));
	if(node == NULL)
		return NULL;
	node->data = data;
	node->next = NULL;
	return node;
}
 
int isEmpty(Queue *queue) {
	return !(queue->front);
}


void enqueue(Queue *queue, int item) {
	Node *node = createQueueNode(item);
 
	if(node == NULL) {
		printf("Queue overflow.\n");
		return;
	}
 
	if(queue->rear == NULL) {
		queue->front = queue->rear = node;
		printf("%d enqueued to the queue.\n",item);
		return;
	}
 
	queue->rear->next = node;
	queue->rear = node;
 
	printf("%d enqueued to the queue.\n",item);
}


int dequeue(Queue *queue) {
	if(queue->front == NULL) {
		printf("Queue is empty.\n");
		return INT_MIN;
	}
 
	Node *node = queue->front;
	queue->front = queue->front->next;
 
	if(queue->front == NULL)
		queue->rear = NULL;
 
	int item = node->data;
	free(node);
 
	return item;
}

 
int front(Queue *queue) {
	if(queue->front == NULL) {
		printf("Queue is empty.\n");
		return INT_MIN;
	}
 
	return queue->front->data;
}

 
int rear(Queue *queue) {
	if(queue->front == NULL) {
		printf("Queue is empty.\n");
		return INT_MIN;
	}
 
	return queue->rear->data;
}


void printQueue(Queue *queue) {
	Node *node = queue->front;
 
	while(node) {
		printf("%d ",node->data);
		node = node->next;
	}
	printf("\n");
}
 
//Driver function
int main(void)
{
	Queue *queue = createQueue(5);
 
	printf("Queue:\n");
	printQueue(queue);
	printf("\n");
 
	printf("%d dequeued from the queue.\n",dequeue(queue));
	printf("\n");
 
	enqueue(queue,1);
	enqueue(queue,2);
	printf("\n");
 
	printf("Queue:\n");
	printQueue(queue);
	printf("\n");
 
	printf("%d dequeued from the queue.\n",dequeue(queue));
	printf("\n");
 
	enqueue(queue,1);
	enqueue(queue,2);
	enqueue(queue,15);
	enqueue(queue,12);
	printf("\n");
 
	printf("Queue:\n");
	printQueue(queue);
	printf("\n");
 
	printf("%d dequeued from the queue.\n",dequeue(queue));
	printf("\n");
 
	printf("Queue:\n");
	printQueue(queue);
	printf("\n");
 
	printf("%d dequeued from the queue.\n",dequeue(queue));
	printf("\n");
 
	printf("Queue:\n");
	printQueue(queue);
	printf("\n");
 
	printf("%d dequeued from the queue.\n",dequeue(queue));
	printf("\n");
 
	printf("Queue:\n");
	printQueue(queue);
	printf("\n");
 
	printf("%d dequeued from the queue.\n",dequeue(queue));
	printf("\n");
 
	printf("Queue:\n");
	printQueue(queue);
	printf("\n");
 
	printf("%d dequeued from the queue.\n",dequeue(queue));
	printf("\n");
 
	printf("Queue:\n");
	printQueue(queue);
	printf("\n");
 
	printf("%d dequeued from the queue.\n",dequeue(queue));
	printf("\n");
 
	return 0;
}