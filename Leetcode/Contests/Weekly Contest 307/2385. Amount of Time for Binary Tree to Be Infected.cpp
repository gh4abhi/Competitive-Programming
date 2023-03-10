// Problem Link - https://leetcode.com/contest/weekly-contest-307/problems/amount-of-time-for-binary-tree-to-be-infected/

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
    
    void DFS(TreeNode* root, TreeNode* par, map<ll,vector<ll>>& adj)
    {
        if(root==nullptr)
            return;
        if(par!=nullptr)
        {
            adj[par->val].push_back(root->val);
            adj[root->val].push_back(par->val);
        }
        DFS(root->left,root,adj);
        DFS(root->right,root,adj);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        map<ll,vector<ll>> adj;
        DFS(root,nullptr,adj);
        queue<ll> q;
        q.push(start);
        q.push(-1);
        ll ans = 0;
        map<ll,ll> vis;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            vis[cur] = 1;
            if(cur==-1)
            {
                if(q.size()==0)
                    return ans;
                ans++;
                q.push(-1);
                continue;
            }
            for(auto i:adj[cur])
                if(vis.count(i)==0)
                    q.push(i);
        }
        return ans;
    }
};