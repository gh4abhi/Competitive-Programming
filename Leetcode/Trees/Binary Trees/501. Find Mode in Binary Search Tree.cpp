// Problem Link - https://leetcode.com/problems/find-mode-in-binary-search-tree/

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
    void DFS(TreeNode* root, ll &maxi, map<ll,ll> &m)
    {
        if(root==nullptr)
            return;
        DFS(root->left,maxi,m) ;
        DFS(root->right,maxi,m);
        m[root->val]++;
        maxi = max(maxi,m[root->val]);
    }
    vector<int> findMode(TreeNode* root) {
        vector<ll> ans;
        ll maxi = 0;
        map<ll,ll> m;
        DFS(root,maxi,m);
        for(auto i:m)
            if(i.second==maxi)
                ans.push_back(i.first);
        return ans;
    }
};