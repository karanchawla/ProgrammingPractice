/*
Author: Karan Chawla
Data Structure: Binary Search Tree 
Deletion of node from BST
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node* left, *right;
};


struct node* newNode(int key)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp-> key = key;
	temp-> left = temp-> right = NULL;
	return temp;
}

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
	if (root==NULL) return newNode(key);

	if (key < root->key) 
		root->left = insert(root->left,key);

	if (key > root->key)
		root->right = insert(root->right, key);

	return root;
}

//function to search for the mininum value in the BST
struct node* minValueNode(struct node* node)
{
	struct node* temp = node;
	while(temp!=NULL)
	{
		temp = node->left;
	}
	return temp;
}

//Delete a key from BST
struct node* deleteNode(struct node* root, int key)
{

	if(root==NULL) return root;

	if(key<root->key) 
		root->left = deleteNode(root->left, key);

	else if (key>root->key)
		root->right = deleteNode(root->right, key);

	//if key is same as root key
	else
	{
		if(root->left==NULL)
		{
			struct node *temp = root->right;
            free(root);
            return temp;
		}

		else if (root->right == NULL)
		{
			struct node * temp = root->left;
			free(root);
			return temp;
		}

		//node with two children
		struct node* temp = minValueNode(root->right);

		root->key = temp->key;

		root->right = deleteNode(root->right,temp->key);
	}

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
	insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 9);
    insert(root, 7);
    insert(root, 8);
    root = deleteNode(root,9);
    inOrder(root);

    return 0;
}