// Problem Link - https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    
    ll ans = INT_MIN;
    ll max(ll a, ll b)
    {
        if(a>b)
            return a;
        return b;
    }
    ll maxPathSumHelper(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        ll leftVal = max(maxPathSumHelper(root->left),0);
        ll rightVal = max(maxPathSumHelper(root->right),0);
        ans = max(leftVal+rightVal+root->val,ans);
        return root->val + max(rightVal,leftVal);
    }
    
    int maxPathSum(TreeNode* root) {
        ll val = maxPathSumHelper(root);
        return ans;
    }
};