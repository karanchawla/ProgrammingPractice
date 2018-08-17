#include <iostream>

using namespace std; 

struct Node
{
	int key;
	Node *left, *right;
};

void preOrder(Node* root)
{
	cout << root->key;

	preOrder(root->left);

	preOrder(root->right);
}