#include <stdio.h> 
#include <stdlib.h>

struct  node
{
	int key;
	struct node* left;
	struct node* right;
	/* data */
};

void inOrder(struct node* root)
{
	if(root!=NULL)
	{
	inOrder(root->left);
	printf("%d\n",root->key);
	inOrder(root->right);	
	}
}

struct node* newNode(int key)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp-> key = key;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* insert(struct node* root, int key)
{
	if(root==NULL) return newNode(key);

	if(key < root->key)
	{
		root->left = insert(root->left,key);
	} else if( key>root->key)
	{
		root->right = insert(root->right,key);
	}
	return root;
}

int main(void)
{
	struct node* root =NULL;
	root = insert(root, 50);
	insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inOrder(root);

    return 0;
}
