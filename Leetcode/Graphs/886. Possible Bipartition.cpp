// Problem Link - https://leetcode.com/problems/possible-bipartition/

#define ll int

class Solution {
public:
    
    bool DFS(ll src, vector<vector<ll>> &adj, vector<ll> &color)
    {
        ll ans = 1;
        for(auto i:adj[src])
        {
            if(color[i]==-1)
            {
                color[i] = 1-color[src];
                ans = ans and DFS(i,adj,color);
            }
            else
                if(color[i]==color[src])
                    return false;
        }
        return ans;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<ll>> adj(n+1);
        for(auto i:dislikes)
            adj[i[0]].push_back(i[1]), adj[i[1]].push_back(i[0]);
        vector<ll> color(n+1,-1);
        ll ans = 1;
        for(ll i=1;i<=n;i++)
            if(color[i]==-1)
                ans = ans and DFS(i,adj,color);
        return ans;
    }
};