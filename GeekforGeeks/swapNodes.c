#include <stdio.h> 
#include <stdlib.h>

struct node
{	
	int data;
	struct node* next;
	/* data */
};

void push(struct node **head_ref, int x){
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = x;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void swapNodes(struct node **head_ref, int x, int y){
	if (x==y) return;

	struct node *prevX, *currX = *head_ref;
	while(currX && currX->data!=x){
		prevX = currX;
		currX = currX->next;
	}

	struct node *prevY, *currY = *head_ref;
	while(currY && currY->data!=y){
		prevY = currY;
		currY = currY->next;
	}

	if(currY==NULL || currX==NULL){
		return;
	}
	
	if (prevX!=NULL){
		prevX->next = currY;
	} else
		*head_ref = currY;

	if(prevY!=NULL){
		prevY->next = currX;
	}else
		*head_ref = currX;

	struct node *temp = currY->next;
   	currY->next = currX->next;
   	currX->next  = temp;

}

void printList(struct node* head){
	while(head!=NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	return;
}

void reverseLinkedList(struct node** head_ref){
	struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}


int main(void){
	struct node* head =NULL;
	for (int i=0;i<5;i++){
		push(&head,i);
	}
	//push(&head, 1);
    //push(&head, 3);
    //push(&head, 4);
    //push(&head, 2);
    //push(&head, 5);

    //swapNodes(&head,2,3);
    reverseLinkedList(&head);
    printList(head);
    return 0;

}