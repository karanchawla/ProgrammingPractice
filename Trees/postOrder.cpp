#include <iostream>

using namespace std; 

struct Node
{
	int key;
	Node *left, *right;
};

void preOrder(Node* root)
{
	if(root==nullptr)
		return;
	
	preOrder(root->left);

	preOrder(root->right);

	cout << root->key;
}