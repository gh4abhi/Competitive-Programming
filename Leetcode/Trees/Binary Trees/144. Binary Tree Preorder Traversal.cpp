//Problem Link - https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vect;
        if(root)
        {
            vector<int> v;
        vect.push_back(root->val);
        v = preorderTraversal(root->left);
            vect.insert(vect.end(),v.begin(),v.end());
        v = preorderTraversal(root->right);
            vect.insert(vect.end(),v.begin(),v.end());
            }
        return vect;
    }
};
