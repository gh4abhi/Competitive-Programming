// Problem Link - https://leetcode.com/problems/longest-univalue-path/

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
    
    ll ans = 0;
    
    pair<ll,ll> DFS(TreeNode* root)
    {
        if(root==nullptr)
            return {10001,0};
        pair<ll,ll> leftVal = DFS(root->left);
        pair<ll,ll> rightVal = DFS(root->right);
        pair<ll,ll> curAns = {root->val,0};
        if(root->val==leftVal.first and root->val==rightVal.first)
            curAns.second = 1+max(leftVal.second,rightVal.second), ans = max(1 + leftVal.second+rightVal.second,ans);
        else if(root->val==leftVal.first)
            curAns.second = 1+leftVal.second, ans = max(ans, 1+leftVal.second);
        else if(root->val==rightVal.first)
            curAns.second = 1 + rightVal.second, ans = max(ans,1+rightVal.second);
        else
            curAns.second = 1;
        return curAns;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        pair<ll,ll> curAns = DFS(root);
        return max(ans-1,0);
    }
};