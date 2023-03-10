// Problem Link - https://leetcode.com/problems/count-sub-islands/

#define ll int

class Solution {
public:
    
    bool DFS(ll i, ll j, vector<vector<ll>> &grid, vector<vector<ll>> & check, vector<vector<ll>> &vis, ll m, ll n)
    {
        vis[i][j] = 1;
        bool ans = 0;
        if(check[i][j]==1)
            ans = 1;
        for(auto x:{1,-1})
        {
            if(i+x>=0 and i+x<m and grid[i+x][j]==1 and vis[i+x][j]==0)
                ans = ans & DFS(i+x,j,grid,check,vis,m,n);
            if(j+x>=0 and j+x<n and grid[i][j+x]==1 and vis[i][j+x]==0)
                ans = ans & DFS(i,j+x,grid,check,vis,m,n);
        }
        return ans;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        ll m = grid1.size();
        ll n = grid1[0].size();
        vector<vector<ll>> vis(m,vector<ll>(n,0));
        ll ans = 0;
        for(ll i=0;i<m;i++)
            for(ll j=0;j<n;j++)
                if(vis[i][j]==0 and grid2[i][j]==1)
                    ans += DFS(i,j,grid2,grid1,vis,m,n);
        return ans;
    }
};