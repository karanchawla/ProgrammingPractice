/*
Karan Chawla
Data Structure: Stacks
Array Implementation
Static but easy implementation
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};

//utility function to create a Stack
struct Stack* createStack(unsigned capacity)
{
	struct Stack* newStack = (struct Stack*) malloc(sizeof(struct Stack));
	newStack->capacity = capacity;
	newStack->top = -1;
	newStack->array = (int*) malloc(newStack->capacity * sizeof(int));
	return newStack; 
}

//check if stack is full
int isFull(struct Stack* stack)
{
	return (stack->top == stack->capacity -1);
}

//check if stack is empty
int isEmpty(struct Stack* stack)
{
	return (stack->top==-1);
}

//utility function to add an element to stack
void push(struct Stack* stack, int x)
{
	if(isFull(stack))
		return;
	stack->array[++stack->top] = x;
	printf("pushed %d to the stack\n",x);
	return;
}

//utility function to remove the top most element from stack
int pop(struct Stack* stack)
{
	if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

//function to get top item from stack
int peek(struct Stack* stack)
{
	if(isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top];
}

//driver program to test the above function
int main(void)
{
	struct Stack* stack = createStack(100);

	push(stack, 2);
	push(stack, 1);
	push(stack, 4);

	printf("Top most element in the stack is: %d",peek(stack));

	return 0;
}