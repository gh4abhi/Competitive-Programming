// Problem Link - https://leetcode.com/contest/weekly-contest-322/problems/minimum-score-of-a-path-between-two-cities/

#define ll int

class Solution {
public:
    
    ll mini = INT_MAX;
    ll op = 0;
    void DFS(ll src, unordered_map<ll,vector<pair<ll,ll>>> &adj, unordered_map<ll,ll> &vis,ll n)
    {
        if(src==n)
            op = 1;
        vis[src] = 1;
        for(auto i:adj[src])
        {
            if(vis[i.first]==0)
                DFS(i.first,adj,vis,n);
            mini = min(mini,i.second);
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<ll,vector<pair<ll,ll>>> adj;
        unordered_map<ll,ll> vis;
        for(auto i:roads)
            adj[i[0]].push_back({i[1],i[2]}), adj[i[1]].push_back({i[0],i[2]});
        DFS(1,adj,vis,n);
        if(op)
            return mini;
        return -1;
    }
};