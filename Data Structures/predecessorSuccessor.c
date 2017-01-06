/*
Author: Karan Chawla
Data Structure: Binary Search Tree 
Inoder predecessor and successor for a key in BST

Credits: GFG
Algorithm: 
1.If root ==NULL return

2.If key is found then
	If its left subtree is not null
        Then predecessor will be the right most 
        child of left subtree or left child itself.
    If its right subtree is not null
    	The successor will be the left most child 
    	of right subtree or right child itself.
	return

3. If key is smaller then root node
        set the successor as root
        search recursively into left subtree
    else
        set the predecessor as root
        search recursively into right subtree
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

struct node *minimumNode(struct node *root)
{
	while(root->left!=NULL) root=root->left;
	return root;
}


struct node *maximumNode(struct node *root)
{
	while(root->right!=NULL) root=root->right;
	return root;
}

void findPreSuc(struct node* root, struct node** pre, struct node** suc, int key)
{
	if(root==NULL) return;

	if(root->key==key)
	{
		//max value in left subtree is predecessor
		if(root->left!= NULL) *pre = maximumNode(root->left);

		//min value in right subtree is successor
		if(root->right!=NULL) *suc = minimumNode(root->right);
	}

	//key is smaller than the root
	if(root->key > key)
	{
		*suc = root;
		findPreSuc(root->left,pre,suc,key);
	}
	else if(root->key < key)
	{
		*pre = root;
		findPreSuc(root->right,pre,suc,key);
	}

	return;
}

int main(void)
{
	/* Create the following BST
				 5
			  /		\
			 3		9
			/ \	   / \
		   2  4	   6  8
    */

	struct node* root = NULL;
	root = insert(root,5);
	insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 9);
    insert(root, 6);
    insert(root, 8);

    inOrder(root);	

    struct node *pre = NULL;
    struct node *suc = NULL;

    findPreSuc(root,&pre,&suc,7);
    
    printf("%d\n%d", pre->key,suc->key);
    
    return 0;
}