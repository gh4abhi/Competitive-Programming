// Problem Link - https://leetcode.com/problems/most-frequent-subtree-sum/

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
    
    ll DFS(TreeNode* root, ll &maxi, map<ll,ll> &m)
    {
        if(root==nullptr)
            return 0;
        ll ans = root->val;
        ans += DFS(root->left,maxi,m) + DFS(root->right,maxi,m);
        m[ans]++;
        maxi = max(maxi,m[ans]);
        return ans;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
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