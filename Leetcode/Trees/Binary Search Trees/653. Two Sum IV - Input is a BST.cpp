// Problem Link - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

#define ll long long

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
    map<ll,ll> m;
    bool DFS(TreeNode* root, ll k)
    {
        if(root==nullptr)
            return false;
        if(m.count(root->val))
            return true;
        ll val = k - root->val;
        m[val]++;    
        return DFS(root->right,k) or DFS(root->left,k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        return DFS(root,k);
    }
};