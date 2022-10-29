// Problem Link - https://leetcode.com/problems/minimum-distance-between-bst-nodes/

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
    
    ll ans = INT_MAX;
    ll pre = -1000000;
    void DFS(TreeNode* root)
    {
        if(root==nullptr)
            return;
        DFS(root->left);
        ans = min(ans,root->val-pre);
        pre = root->val;
        DFS(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        DFS(root);
        return ans;
    }
};