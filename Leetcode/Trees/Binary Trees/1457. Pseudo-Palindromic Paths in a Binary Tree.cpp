// Problem Link - https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

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
    
    void DFS(TreeNode* root, unordered_map<ll,ll> &m, ll &ans)
    {
        if(root==nullptr)
            return;
        m[root->val]++;
        if(!root->left and !root->right)
        {
            ll ok = 1;
            ll op = 1;
            for(auto i:m)
            {
                if(i.second&1 and ok)
                    ok = 0;
                else if(i.second&1)
                    op = 0;
            }
            if(op)
                ans += 1;
        }
        DFS(root->left,m,ans);
        DFS(root->right,m,ans);
        m[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ll ans = 0;
        unordered_map<ll,ll> m;
        DFS(root,m,ans);
        return ans;
    }
};