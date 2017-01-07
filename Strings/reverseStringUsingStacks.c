/*
Karan Chawla
Algorithm: String reversal using stacks
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

//function to reverse a string
void reverseString(char str[])
{
	int size = strlen(str);
	struct node* stack = NULL;
	for (int i=0;i<size;i++)
		push(&stack,(int)str[i]);

	for(int i=0;i<size;i++)
		str[i] = pop(&stack);
}

//drive program
int main(void)
{	
	char str[] = "I must not Fear. Fear is a mind killer. I will face my fear. I will permit it to pass over me and through me.\
	And when it has gone past there'll be nothing, only I will remain.";
	reverseString(str);
	printf("%s", str);
	return 0;
}

