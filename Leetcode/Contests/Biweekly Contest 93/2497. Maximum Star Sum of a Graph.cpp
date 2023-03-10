// Problem Link - https://leetcode.com/contest/biweekly-contest-93/problems/maximum-star-sum-of-a-graph/

#define ll int

class Solution {
public:
    ll ans = INT_MIN;
    void DFS(ll src, vector<ll> &vals, vector<vector<ll>> &adj, ll k, vector<ll> &vis)
    {
        vis[src] = 1;
        priority_queue<ll> pq;
        ll op = vals[src];
        for(auto i:adj[src])
        {
            if(vis[i]==0)
                DFS(i,vals,adj,k,vis);
            pq.push(vals[i]);
        }
        ans = max(ans,op);
        while(pq.size() and k--)
            op += pq.top(), pq.pop(), ans = max(ans,op);
    }
    
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        ll n = vals.size();
        vector<vector<ll>> adj(n);
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<ll> vis(n,0);
        for(ll i=0;i<n;i++)
            if(vis[i]==0)
                DFS(i,vals,adj,k,vis);
        return ans;
    }
};