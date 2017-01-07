/*
Author: Karan Chawla
Data Structure : Linked List
*/

#include <stdio.h> 
#include <stdlib.h> 

struct node
{
	int data;
	struct node* next;
};

//utility function to print list
void printList(struct node* head)
{
	struct node* temp = head;
	while(temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	return;
}

/*
3 ways to add a node: 
1. At the front 
2. After a given node
3. At the end
*/

//front insert
void push(struct node** head, int newData)
{
	struct node* newNode = (struct node*) malloc(sizeof(struct node));

	newNode->data = newData;

	newNode->next = (*head);

	*head = newNode;
}

//insert after a node
void insertAfter(struct node* prevNode, int newData)
{
	if(prevNode==NULL)
	{
		printf("Previous node is NULL\n");
		return;
	}

	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	
	newNode->data = newData;
	newNode->next = prevNode->next;
	prevNode->next = newNode;
	
	return;
}

//insert at the end
void insertEnd(struct node** head, int newData)
{
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = newData;
	newNode->next = NULL;
	
	//linked list empty - make head new node
	if(*head==NULL) 
	{
		*head = newNode;
		return;
	}

	struct node* temp = *head;

	//else traverse till the last node
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}

	temp->next = newNode;
	return;
}



//create a linked list with 3 nodes
int main(void)
{
	struct node* head = NULL; 
	struct node* second = NULL; 
	struct node* third = NULL;

	head = (struct node*) malloc(sizeof(struct node));
	second = (struct node*) malloc(sizeof(struct node));
	third = (struct node*) malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;
	insertEnd(&head,4);
	printList(head);

	return 0;
}