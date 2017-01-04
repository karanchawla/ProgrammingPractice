#include <stdio.h>
#include <stdlib.h> 

struct node
{
	int key;
	struct node* left, *right;
};

//utility functiont to create a new BST
struct node *newNode(int item) 
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp-> key = item;
	temp->left = temp->right = NULL;
	return temp;
}

//utility function to do BST traversal 
void inOrder(struct node* root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		printf("%d\n", root->key);
		inOrder(root->right);
	}
}

//utility function to insert new node in BST with given key
struct node* insert(struct node* node, int key)
{
	if(node==NULL) return newNode(key);

	if(key < node->key)
	{	
		node->left = insert(node->left, key);
	} else if (key > node-> key)
	{
		node->right = insert(node->right,key);
	}

	return node;
}

//function to find the minimum node in BST
struct node* minValueNode(struct node* node)
{
	//struct node* current = node;
	while(node->left!=NULL)
		node = node-> left;

	return node;
}

//function to find and delete key in BST

struct node* deleteNode(struct node* root, int key)
{
	//oif tree is empty
	if(root==NULL) return root;

	if(key<root->key)
	{
		root->left = deleteNode(root->left,key);
	}

	else if (key>root->key)
	{
		root->right = deleteNode(root->right, key);
	}

	//if key is the same as root key
	else
	{

		if(root->left == NULL)
		{
			struct node* temp = root -> right;
			free(root);
			return temp;
		}
		else if(root -> right ==NULL)
		{
			struct node* temp = root -> left ;
			free(root);
			return temp;
		}

		struct node* temp = minValueNode(root->right);

		root->key = temp->key;

		root->right = deleteNode(root->right, temp->key);
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
	//inOrder(root);
	deleteNode(root,20);
	printf("Minimum value key is %d",minValueNode(root)->key);
	return 0;
}
