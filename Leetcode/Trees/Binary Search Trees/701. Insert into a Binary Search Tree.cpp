// Problem Link - https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
     if(root==nullptr)
     {
         TreeNode* newNode = new TreeNode(val);
         root = newNode;
         return root;
     }
        if(root->val>val)
        {
            if(root->left==nullptr)
            {
                TreeNode* newNode = new TreeNode(val);
                root->left = newNode;
            }
            else
            {
                root->left = insertIntoBST(root->left,val);
            }
        }
        else
        {
            if(root->right==nullptr)
            {
                TreeNode* newNode = new TreeNode(val);
                root->right = newNode;
            }
            else
            {
                root->right = insertIntoBST(root->right,val);
            }
        }
        return root;
    }
};
