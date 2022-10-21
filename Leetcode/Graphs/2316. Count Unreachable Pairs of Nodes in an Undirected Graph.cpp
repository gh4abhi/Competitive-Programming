// Problem Link - https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

#define ll long long

class Solution {
public:
    
    ll DFS(ll src, vector<ll> &vis, vector<vector<ll>> &adj)
    {
        vis[src] = 1;
        ll ans = 1;
        for(auto i:adj[src])
            if(vis[i]==0)
                ans += DFS(i,vis,adj);
        return ans;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<ll>> adj(n);
        for(auto i:edges)
            adj[i[0]].push_back(i[1]), adj[i[1]].push_back(i[0]);
        vector<ll> vis(n,0);
        vector<ll> comp;
        for(ll i=0;i<n;i++)
            if(vis[i]==0)
                comp.push_back(DFS(i,vis,adj));
        ll ans = 0;
        for(auto i:comp)
            ans += i*(n-i);
        return ans/2ll;
    }
};