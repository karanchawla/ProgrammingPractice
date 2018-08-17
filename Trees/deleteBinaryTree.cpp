#include <iostream>

using namespace std; 

struct Node
{
	int key; 
	Node *left, *right;
};

void deleteBinaryTree(Node* root)
{
	if(root==nullptr)
		return;

	deleteBinaryTree(root->left);
	deleteBinaryTree(root->right);

	delete root;

	root = nullptr;
}