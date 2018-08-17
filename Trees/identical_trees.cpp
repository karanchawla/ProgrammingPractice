#include <iostream>

using namespace std; 

struct Node
{
	int key;
	Node *left, *right;
};

bool isIdentical(Node* x, Node* y)
{
	if(x == nullptr && y == nullptr)
		return true; 

	return (x->key == y->key) && (x && y) && isIdentical(x->left, y->left)
	&& isIdentical(x->right, y->right);
}