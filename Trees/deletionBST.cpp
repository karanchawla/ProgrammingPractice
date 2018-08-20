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
	node->left = left;
	node->right = right;

	return node;
}

Node* insert(Node* root, int key)
{
	if(root == nullptr)
	{
		root = newNode(key);
		return root;
	}

	if(key < root->key)
		insert(root->left, key);
	else 
		insert(root->right, key);

	return root;
}


void searchKey(Node* &root, int key, Node* &parent)
{
	while(curr !=nullptr && curr->data != key)
	{
		parent = curr;

		if(key < curr->key)
			curr = curr->left;
		else 
			curr = curr->right;
	}
}


Node* InOrderSucc(Node* &root)
{
	while(curr->left!=nullptr)
		curr = curr->left;

	return curr;
}


bool deleteNode(Node* &root, int key)
{
	Node* parent = nullptr;

	Node* curr = root;

	if(curr == nullptr)
		return;

	searchKey(curr, key, parent);

	if(curr->left == nullptr && curr->right == nullptr)
	{
		if(curr !=root)
		{
			if(parent->left == curr)
				parent->left = nullptr;
			else 
				parent->right = nullptr;
		}
		else 
			root = nullptr;

		delete curr;
	}
	else if(curr->left && curr->right)
	{
		Node* successor = InOrderSucc(curr->right);

		int val = successor->key;

		deleteNode(root, val);

		curr->key = val;
	}
	else // has one child node
	{
		// find the child node
		Node* child = (curr->left) ? curr->left : curr->right;

		if(curr != root)
		{
			if(curr == parent->left)
				parent->left = child;
			else 
				parent->right = child;
		}
		else 
			root = child;

		delete curr;
	}

}