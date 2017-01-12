/*
Karan Chawla
In Order Traversal of trees using stacks
*/

#include <stdio.h> 
#include <stdlib.h> 

typedef struct tnode
{
	int data;
	struct tnode* left, *right;
}tNode;

typedef struct snode
{
	int data;
	struct snode* next;
}sNode;

//Stack Functions
void push(sNode** top_ref, tNode *t);
tNode *pop(sNode** top_ref);
int isEmpty(sNode *top);

void inOrder(tNode* root)
{
	//Set current to root
	tNode* current = root;
	//Initialize stack
	sNode* s = NULL;
	int done = 0;

	while(!done)
	{
		if(current!=NULL)
		{
			push(&s,current);
			current = current->left;
		}

		else
		{
			if(!isEmpty(s))
			{
				current = pop(&s);
				printf("%d",current->data);

				current = current -> right;
			}
			else
				done = 1;
		}
	}
}


//utility function to push an item in stack
void push(sNode** top_ref, tNode *t)
{
 
  sNode* new_tNode =
            (sNode*) malloc(sizeof(sNode));
 
  if(new_tNode == NULL)
  {
     printf("Stack Overflow \n");
     getchar();
     exit(0);
  }            
 
  new_tNode->data  = t->data;
 
  new_tNode->next = (*top_ref);   
 
  (*top_ref)    = new_tNode;
}

//utility function for checking if stack is empty or not
int isEmpty(sNode *top)
{
   return (top == NULL)? 1 : 0;
}   

tNode *pop(sNode** top_ref)
{
  tNode *res;
  sNode *top;
 
  /*If sNode is empty then error */
  if(isEmpty(*top_ref))
  {
     printf("Stack Underflow \n");
     getchar();
     exit(0);
  }
  else
  {
    top = *top_ref;
    res->data = top->data;
    *top_ref = top->next;
    free(top);
    return res;
  }
}


tNode* newtNode(int data)
{
	tNode* node = (tNode*)malloc(sizeof(tNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int max(int a, int b)
{
  if(a>b)
    return a;
  else
    return b;
}

int getHeight(tNode* root){
    // Write your code here
    if(root==NULL) return 0; 
    
    int leftHeight = 0;
    int rightHeight = 0;

    while(root->left!=NULL)
    {
      leftHeight++;
      root = root->left;
    }

    while(root->right!=NULL)
    {
      rightHeight++;
      root = root->right;
    }

    return max(leftHeight,rightHeight);
    
}

int main()
{
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  tNode *root = newtNode(1);
  root->left        = newtNode(2);
  root->right       = newtNode(3);
  root->left->left  = newtNode(4);
  root->left->right = newtNode(5); 
  root->right->right = newtNode(7);
  root->right->right = newtNode(8);


  printf("%d\n", getHeight(root));
  //inOrder(root);
 
  getchar();
  return 0;
}
