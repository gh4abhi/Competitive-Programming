// Problem Link - https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/

#define ll int

class Solution {
public:

    vector<ll> DFS(ll root, vector<vector<ll>> &adj, string &labels, vector<ll> &vis, vector<ll> &ans)
    {
        vector<ll> m(26,0);
        vis[root] = 1;
        vector<vector<ll>> op;
        for(auto i:adj[root])
            if(vis[i]==0)
                op.push_back(DFS(i,adj,labels,vis,ans));
        m[labels[root]-'a']++;
        for(auto j:op)
            for(ll i=0;i<j.size();i++)
                m[i] += j[i];
        ans[root] = m[labels[root]-'a'];
        return m;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<ll> vis(n,0);
        vector<vector<ll>> adj(n);
        for(auto i:edges)
            adj[i[0]].push_back(i[1]), adj[i[1]].push_back(i[0]);
        vector<ll> ans(n,0);
        DFS(0,adj,labels,vis,ans);
        return ans;
    }
};