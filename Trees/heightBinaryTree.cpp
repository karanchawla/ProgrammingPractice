#include <iostream>
#include <queue>

using namespace std; 

// level order traversal

struct Node
{
	int key; 
	Node* left, *right;
};

int height(Node* root)
{
	if(root == nullptr)
		return 0;

	queue<Node*> q;
	q.push(root);
	Node* front = nullptr;
	int height = 0 ;

	while(!q.empty())
	{
		int size = q.size();

		// process every node at current level and 
		// add it to the queue
		while(size--)
		{
			front = q.front();
			q.pop();

			if(front->left) q.push(front->left);
			if(front->right) q.push(front->right);

		}

		height++;
	}

	return height;

}