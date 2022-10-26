// Problem Link - https://leetcode.com/problems/number-of-closed-islands/

#define ll int

class Solution {
public:
    
    ll DFS(ll i, ll j, ll m, ll n, vector<vector<ll>> &grid, vector<vector<ll>> &vis)
    {
        vis[i][j] = 1;
        ll ans = 1;
        for(auto x:{-1,1})
        {
            if(i+x>=0 and i+x<m and vis[i+x][j]==0 and grid[i+x][j]==0)
                ans += DFS(i+x,j,m,n,grid,vis);
            if(j+x>=0 and j+x<n and vis[i][j+x]==0 and grid[i][j+x]==0)
                ans += DFS(i,j+x,m,n,grid,vis);
        }
        return ans;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        ll m = grid.size();
        ll n = grid[0].size();
        vector<vector<ll>> vis(m,vector<ll>(n,0));
        for(ll i=0;i<m;i++)
        {
            if(vis[i][0]==0 and grid[i][0]==0)
                DFS(i,0,m,n,grid,vis);
            if(vis[i][n-1]==0 and grid[i][n-1]==0)
                DFS(i,n-1,m,n,grid,vis);
        }
        for(ll i=0;i<n;i++)
        {
            if(vis[0][i]==0 and grid[0][i]==0)
                DFS(0,i,m,n,grid,vis);
            if(vis[m-1][i]==0 and grid[m-1][i]==0)
                DFS(m-1,i,m,n,grid,vis);
        }
        ll ans = 0;
        for(ll i=1;i<m;i++)
            for(ll j=1;j<n;j++)
                if(vis[i][j]==0 and grid[i][j]==0)
                    ans+=1, DFS(i,j,m,n,grid,vis);
        return ans;
    }
};