#include <iostream>

using namespace std; 

// insertion in BST

struct Node
{
	int key;
	Node* left, *right;
};

Node* newNode(int key)
{
	Node* node = new Node; 
	node->key = key;
	node->left = nullptr;
	node->right = nullptr;

	return node;
}

void inorder(Node* root)
{
	if(root == nullptr)
		return;

	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}

void insertNode(Node* &root, int key)
{
	if(root == nullptr)
	{
		root = newNode(key);
		return;
	}

	if(key < root->key)
		insertNode(root->left, key);
	else
		insertNode(root->right, key);
}

int main()
{
    Node* root = nullptr;
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    for (int key : keys)
        insertNode(root, key);
 
    inorder(root);
 
    return 0;
}