/*
Karan Chawla
Data Structure: Trees
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}Node;

Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));

	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int main()
{

	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);

	root->left->left = newNode(4);

	/*		1
		   / \
		  2   3
		 /     \
		4      NULL
	   /  \ 
	  NULL NULL
	*/  
	return 0;
}