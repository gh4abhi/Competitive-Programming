// Problem Link - https://leetcode.com/problems/path-sum-iii/

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
    
    ll ans = 0;
    void DFS(TreeNode* root, ll targetSum, ll sum,map<ll,ll> & m)
    {
        if(root==nullptr)
            return;
        if(sum+root->val==targetSum)
            ans++;
        ans += m[sum+root->val-targetSum];
        m[sum+root->val]++;
        DFS(root->left,targetSum,sum+root->val,m);
        DFS(root->right,targetSum,sum+root->val,m);
        m[sum+root->val]--;
    }   
    
    int pathSum(TreeNode* root, int targetSum) {
        map<ll,ll> m;
        DFS(root,targetSum,0,m);
        return ans;
    }
};