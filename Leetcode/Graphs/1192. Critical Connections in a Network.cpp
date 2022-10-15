// Problem Link - https://leetcode.com/problems/critical-connections-in-a-network/

#define ll int

class Solution {
public:
    
    void DFS(ll src, ll par, vector<ll> &tin, vector<ll> &low, vector<ll> &vis, vector<vector<ll>> &adj, vector<vector<ll>> &ans, ll timer)
    {
        vis[src] = 1;
        tin[src] = low[src] = timer++;
        for(auto i:adj[src])
        {
            if(i==par)
                continue;
            if(vis[i]==0)
            {
                DFS(i,src,tin,low,vis,adj,ans,timer);
                low[src] = min(low[src],low[i]);
                if(tin[src]<low[i])
                    ans.push_back({i,src});
            }
            else
                low[src] = min(low[src],tin[i]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<ll> tin(n,-1);
        vector<ll> low(n,-1);
        vector<ll> vis(n,0);
        vector<vector<ll>> adj(n);
        vector<vector<ll>> ans;
        ll timer = 0;
        for(auto i:connections)
            adj[i[0]].push_back(i[1]), adj[i[1]].push_back(i[0]);
        for(ll i=0;i<n;i++)
            if(vis[i]==0)
                DFS(i,-1,tin,low,vis,adj,ans,timer);
        return ans;
    }
};