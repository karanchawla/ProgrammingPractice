/*
Karan Chawla
Data Structure: Stacks
Linked List Implementation
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
	int data;
	struct node* next;
};

struct node* newNode(int x)
{
	struct node* stackNode = (struct node*) malloc(sizeof(struct node));
	stackNode->data = x;
	stackNode->next = NULL;
	return stackNode;
}

int isEmpty(struct node* head)
{
	if(head->next==NULL)
		return 1;
	return 0;
}

void push(struct node** root, int x)
{
	struct node* stackNode = newNode(x);
	stackNode->next = *root;
	*root = stackNode;
	printf("Pushed %d to the stack\n",x);
}

int pop(struct node** root)
{
	if(isEmpty(*root))
		return INT_MIN;
	struct node* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;

	free(temp);
	return popped;
}

int peek(struct node* root)
{
	if(isEmpty(root))
		return INT_MIN;
	return root->data;
}

//drive program
int main(void)
{
	struct node* root = NULL;

	push(&root, 4);
	push(&root, 21);
	push(&root, 8);

	printf("Top element is %d\n", peek(root));

	return 0;
}