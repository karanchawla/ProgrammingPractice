#include <stdio.h>
#include <stdlib.h>

struct node
{
	/* data */
	int data;
	struct node* next; 
};

void push(struct node **head_ref, int new_data){

	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node-> data = new_data;
	new_node-> next = (*head_ref);
	(*head_ref) = new_node;
}

int getCount(struct node* head){
	int count = 0;
	struct node* current = head; 
	while(current!=NULL){
		count++;
		current = current->next;
	}
	return count;
}

int recurGetCount(struct node* head){
	int count;
	if(head==NULL){
		return 0;
	}

	return 1 + recurGetCount(head->next);
}

void deleteFirst(struct node** head_ref){
	
	
	if(*head_ref!=NULL){
		struct node* current = (*head_ref);
		(*head_ref) = (*head_ref)->next;
		free(current);
	}
}

void swapNodes()

int main(void){
	struct node* head =NULL;
	push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);

    deleteFirst(&head);
    printf("%d\n", getCount(head));
    printf("%d\n", recurGetCount(head) );
}