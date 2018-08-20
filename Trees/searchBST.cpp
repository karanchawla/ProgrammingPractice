#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std; 

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

bool searchKey(Node* root, int key)
{
	if(root == nullptr)
		return false;

	if(root->key == key)
		return true; 

	if(key < root->key)
		searchKey(root->left, key);
	else 
		searchKey(root->right, key);
}