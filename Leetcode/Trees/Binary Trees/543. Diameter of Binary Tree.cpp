// Problem Link - https://leetcode.com/problems/diameter-of-binary-tree/

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
    pair<ll,ll> diameterOfBinaryTreeHelper(TreeNode* root)
    {
        if(root == nullptr)
        {
            return make_pair(0,0);
        }
        pair<ll,ll> lNode = diameterOfBinaryTreeHelper(root->left);
        pair<ll,ll> rNode = diameterOfBinaryTreeHelper(root->right);    
        ll lHeight = lNode.first;
        ll rHeight = rNode.first;
        ll lDia = lNode.second;
        ll rDia = rNode.second;
        ll finalHeight = 1 + max(lHeight, rHeight);
        ll finalDia = max(lHeight + rHeight, max(lDia,rDia));
        return make_pair(finalHeight, finalDia);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterOfBinaryTreeHelper(root).second;
    }
};
