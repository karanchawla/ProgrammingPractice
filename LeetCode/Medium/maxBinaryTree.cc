#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findBottomLeftValue(TreeNode* root) 
{
    pair<int,int> result(root->val,1);
    if(root!=NULL)
        dfs(root, 1, result);
    return result.first;
}

void dfs(TreeNode* root,int height,pair<int,int>& res)
{
    if(!root->left && !root->right && height>res.second)
    {
        res = make_pair(root->val, height);
    }
    if(root->left) dfs(root->left, height+1, res);
    if(root->right) dfs(root->right, height+1, res);
}