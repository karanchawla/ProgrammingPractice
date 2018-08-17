#include <iostream>

using namespace std; 


struct Node
{
	int key; 
	Node *left, *right;
};

void inOrder(Node* root)
{
	if(root==nullptr)
		return;

	inOrder(root->left);

	cout << root->key;

	inOrder(root->right);
}

//To Do
// Add non recursive in order traversal implementation