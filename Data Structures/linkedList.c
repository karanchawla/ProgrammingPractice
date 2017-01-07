/*
Author: Karan Chawla
Data Structure : Linked List
*/

//To Do:
// Implement Merge function for two linked lists


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

//length of linked list
// Time Complexity : O(n)
int getCount(struct node* head)
{
    // Base case
    if (head == NULL)
        return 0;
 
    return 1 + getCount(head->next);
}

//Delete a linked list node at a given position
void deleteNode(struct node** head, int position)
{
	if(*head==NULL) return;

	struct node* temp = *head;

	//if head is removed
	if(position==0)
	{	
		*head = temp->next; //change head
		free(temp); // free old head
		return;
	}
	//else
	if(position<getCount(*head))
	{
		for(int i=0; (temp!=NULL && i<position-1);i++)
		{
			temp = temp->next;
		}	
	}
	//temp->next is the node to be deleted
	struct node* next = temp->next->next;

	free(temp->next);

	temp->next = next;
}

//swap nodes without swapping data
void swap(struct node** head, int x, int y)
{	
	if(x==y) return;

	struct node* first = *head;
	
	struct node* bfirst = first; //before first

	struct node* second = *head;
	
	while(first->data!=x)
	{
		bfirst = first;
		first = first->next;
	}

	while(second->data!=y)
	{
		second = second->next;
	}

	//swapping of three pointers
	struct node* temp = bfirst->next;
	first->next = second->next;
	bfirst->next = second;
	second->next = temp;
}

//function to reverse a linked list
static void reverse(struct node** head)
{
    struct node* prev   = NULL;
    struct node* current = *head;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head = prev;
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
	//deleteNode(&head, 2);
	printf("\nCount:%d\n", getCount(head));
	swap(&head,2,3);
	printList(head);
	return 0;
}