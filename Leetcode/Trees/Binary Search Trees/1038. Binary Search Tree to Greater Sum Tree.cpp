// Problem Link - https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
    
    void DFS(TreeNode* root, ll &op)
    {
        if(root==nullptr)
            return;
        DFS(root->right,op);
        root->val+=op;
        op=root->val;
        DFS(root->left,op);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        ll op = 0;
        DFS(root,op);
        return root;
    }
};