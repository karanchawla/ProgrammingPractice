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

void push(struct node** head, int key)
{
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	struct node* temp = *head;
	newNode->data = key;
	newNode->next = *head;

	 if (*head!= NULL)
    {
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
    }
    else
        newNode->next = newNode; 
 
    *head = newNode;
}

void printList(struct node *head)
{
    struct node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
}

int main()
{
    struct node *head = NULL; 
    // 4->3->2->1
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    printList(head);
 
    return 0;
}