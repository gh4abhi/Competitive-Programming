// Problem Link - https://leetcode.com/problems/longest-cycle-in-a-graph/

#define ll int

class Solution {
public:
    
    ll ans = -1;
    
    void DFS(ll src, ll &ind, vector<vector<ll>> &adj, vector<ll> &vis, vector<ll> &dfsVis, vector<ll> &tin)
    {
        vis[src] = 1;
        dfsVis[src] = 1;
        tin[src] = ind++;
        for(auto i:adj[src])
        {
            if(vis[i]==0)
                DFS(i,ind,adj,vis,dfsVis,tin);
            else if(dfsVis[i])
                ans = max(ans,abs(tin[src]-tin[i]) + 1);
        }
        dfsVis[src] = 0;
    }
    
    int longestCycle(vector<int>& edges) {
        ll n = edges.size();
        vector<ll> vis(n,0);
        vector<ll> dfsVis(n,0);
        vector<ll> tin(n,0);
        vector<vector<ll>> adj(n);
        for(ll i=0;i<n;i++)
            if(edges[i]!=-1)
                adj[i].push_back(edges[i]);
        ll ind = 0;
        for(ll i=0;i<n;i++)
            if(vis[i]==0)
                DFS(i,ind,adj,vis,dfsVis,tin);
        return ans;
    }
};