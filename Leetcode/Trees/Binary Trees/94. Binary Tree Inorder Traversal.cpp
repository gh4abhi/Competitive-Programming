//Problem Link - https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
     vector<int> vect,v;
        if(root != nullptr)
        {
            v = inorderTraversal(root->left);
            vect.insert(vect.end(),v.begin(),v.end());
            vect.push_back(root->val);
            v = inorderTraversal(root->right);
            vect.insert(vect.end(),v.begin(),v.end());            
        }
        return vect;
    }
};
