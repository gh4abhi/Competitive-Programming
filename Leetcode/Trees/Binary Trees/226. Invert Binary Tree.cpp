//Problem Link - https://leetcode.com/problems/invert-binary-tree/

/*
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
    TreeNode* invertTree(TreeNode* root) {
        if(root)
        {
        TreeNode * mirroredroot = new TreeNode(root->val);
        if(root->left)
        {
            mirroredroot ->right = invertTree(root->left);
        }
        if(root->right)
        {
            mirroredroot ->left = invertTree(root->right);
        }
            
        return mirroredroot;
        }
        return nullptr;
    }
};
