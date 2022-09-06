// Problem Link - https://leetcode.com/problems/binary-tree-pruning/

#define ll int

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    ll DFS(TreeNode* root)
    {
        if(root->left==nullptr and root->right==nullptr)
        {
            if(root->val==1)
                return 1;
            root=nullptr;
            return 0;
        }
        ll op = 0;
        if(root->left)
        {
            if(DFS(root->left))
                op = 1;
            else
                root->left = nullptr;
        }
        if(root->right)
        {
            if(DFS(root->right))
                op = 1;
            else
                root->right = nullptr;
        }
        if(op or root->val==1)
            return 1;
        return 0;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(DFS(root))
            return root;
        return nullptr;
    }
};