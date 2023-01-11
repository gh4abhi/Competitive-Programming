// Problem Link - https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/

#define ll int

class Solution {
public:

    bool DFS(ll root, vector<vector<ll>> &adj, ll &ans, vector<bool> &check, vector<ll> &vis)
    {
        vis[root] = 1;
        ll ok = 0;
        if(check[root])
            ok = 1;
        for(auto i:adj[root])
            if(vis[i]==0)
                if(DFS(i,adj,ans,check,vis))
                    ok = 1;
        if(ok and root!=0)
            ans += 2;
        return ok;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<ll>> adj(n);
        for(auto i:edges)
            adj[i[0]].push_back(i[1]), adj[i[1]].push_back(i[0]);
        vector<ll> vis(n,0);
        ll ans = 0;
        DFS(0,adj,ans,hasApple,vis);
        return ans;      
    }
};