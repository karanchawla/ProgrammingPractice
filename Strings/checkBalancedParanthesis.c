/*
Karan Chawla
Algorithm: Check for parathesis
use stacks to check the balanced paranthesis in an expression
*/

//Time Complexity: O(n)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

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

int isMatchingPair(char c1, char c2)
{
	if(c1== '(' && c2 == ')')
		return 1;
	else if(c1 == '[' && c2 ==']')
		return 1;
	else if(c1 == '{' && c2 =='}')
		return 1;
	else 
		return 0;
}

int checkParathesisBalanced(char *str)
{
	int size = strlen(str);
	struct node* stack = NULL;
	int i=0;

	while (str[i])
	{
		if(str[i]=='[' || str[i]=='(' || str[i]=='{')
		{
			push(&stack,(int)str[i]);
		}

		if(str[i]=='}' || str[i]==')' || str[i]==']')
		{
			if (stack==NULL)
				return 0;

			else if (!isMatchingPair((char)pop(&stack),str[i]))
				return 0;
		}
		i++;
	}	

	if (stack==NULL)
		return 1;
	else
		return 0;
}

int main(void)
{
	char exp[100] = "{()}[]";
  if (checkParathesisBalanced(exp))
    printf("\nBalanced ");
  else
    printf("\nNot Balanced ");  
  return 0;
}