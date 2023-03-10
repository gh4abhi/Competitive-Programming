// Problem Link - https://leetcode.com/contest/weekly-contest-305/problems/reachable-nodes-with-restrictions/

#define ll int

class Solution {
public:
    
    ll ans = 0;
    
    void DFS(ll n, map<ll,vector<ll>>& adj, map<ll,ll> &vis, map<ll,ll> &res, ll start)
    {
        vis[start] = 1;
        ans++;
        for(auto i:adj[start])
        {
            if(vis[i]==0)
            {
                if(res.count(i)==0)
                    DFS(n,adj,vis,res,i);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        map<ll,vector<ll>> adj;
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        map<ll,ll> vis;
        for(ll i=0;i<n;i++)
            vis[i] = 0;
        map<ll,ll> res;
        for(auto i:restricted)
            res[i]++;
        DFS(n,adj,vis,res,0);
        return ans;
    }
};