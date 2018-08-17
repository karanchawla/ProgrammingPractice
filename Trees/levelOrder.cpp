#include <iostream>
#include <queue>

using namespace std; 

//Level Order Traversal of Binary tree

struct Node
{
	int key;
	Node *left, *right;
};

void levelOrderTraversal(Node* root)
{
	queue<Node*> q;
	q.push(root);

	Node* front = nullptr;

	while(!q.empty())
	{
		front = q.front();
		q.pop();

		cout << front->key << endl;

		if(front->left) q.push(front->left);
		if(front->right) q.push(front->right);
	}
}