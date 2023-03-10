// Problem Link - https://leetcode.com/problems/count-complete-tree-nodes/

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
    ll leftHeight(TreeNode* root)
    {
        ll height = 0;
        while(root)
            height++,root = root->left;
        return height;
    }
    ll rightHeight(TreeNode* root)
    {
        ll height = 0;
        while(root)
            height++,root = root->right;
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr)
            return 0;
        ll lef = leftHeight(root);
        ll rig = rightHeight(root);
        if(lef==rig)
            return (1<<lef)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};