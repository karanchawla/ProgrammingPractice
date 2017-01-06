/*
Author: Karan Chawla
Data Structure: Binary Search Tree 
Insertion and InOder Traversal of BST
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node* left;
	struct node* right;
};

//Utility function to create a new node
struct node* newNode(int key)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp-> key = key;
	temp-> left = temp->right = NULL;
	return temp;
}

//utility function to do inorder traversal of BST
void inOrder(struct node* root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		printf("%d\n",root->key);
		inOrder(root->right);
	}
}

struct node* insert(struct node* root, int key)
{
	if(root==NULL) return newNode(key);

	if(key > root->key)
	{
		root->right = insert(root->right, key);
	} else if(key < root->key)
		root->left = insert(root->left, key);

	return root;
}

int main(void)
{
	/* Create the following BST
				 5
			  /		\
			 3		9
			/ \	   / \
		   2  4	   7  8
    */

	struct node* root = NULL;
	root = insert(root,5);
	root = insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 9);
    insert(root, 7);
    insert(root, 8);

    inOrder(root);	

    return 0;
}