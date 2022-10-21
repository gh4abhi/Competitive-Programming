// Problem Link - https://leetcode.com/problems/all-paths-from-source-to-target/

#define ll int

class Solution {
public:
    
    void DFS(ll src, vector<vector<ll>> &adj, vector<vector<ll>> &ans, vector<ll>& cur, vector<ll> &vis, ll n)
    {
        if(src==n-1)
        {
            ans.push_back(cur);
            return;
        }
        for(auto i:adj[src])
        {
            if(vis[i]==0)
            {
                cur.push_back(i);
                vis[i] = 1;
                DFS(i,adj,ans,cur,vis,n);
                cur.pop_back();
                vis[i] = 0;
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<ll>> ans;
        vector<ll> vis(graph.size(),0);
        vector<ll> cur = {0};
        vis[0] = 1;
        DFS(0,graph,ans,cur,vis,graph.size());
        return ans;
    }
};