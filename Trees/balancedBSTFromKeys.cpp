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

void convert(vector<int> keys, int low, int high, Node* &root)
{
	if(low > high)
		return;

	int mid = (low + high) / 2;

	root = newNode(keys[mid]);

	convert(keys, low, mid - 1, root->left);

	convert(keys, mid + 1, high, root->right);

}

Node* createTree(vector<int> keys)
{
	sort(keys.begin(), keys.end());

	Node* root = nullptr;
	covert(keys, 0, keys.size() - 1, root);
}