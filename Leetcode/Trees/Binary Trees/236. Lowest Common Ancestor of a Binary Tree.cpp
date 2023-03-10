// Problem Link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* DFS(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==nullptr or root==p or root==q)
            return root;
        TreeNode* lef = DFS(root->left,p,q);
        TreeNode* rig = DFS(root->right,p,q);
        if(!lef)
            return rig;
        else if(!rig)
            return lef;
        else
            return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return DFS(root,p,q);
    }
};