// Problem Link - https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves

#define ll int

class Solution {
  public:
    
    void DFS(ll i, ll j, vector<vector<ll>> &grid, vector<vector<ll>> &vis, ll m, ll n)
    {
        vis[i][j] = 1;
        for(auto x:{-1,1})
        {
            if(i+x>=0 and i+x<m and grid[i+x][j]==1 and vis[i+x][j]==0)
                DFS(i+x,j,grid,vis,m,n);
            if(j+x>=0 and j+x<n and grid[i][j+x]==1 and vis[i][j+x]==0)
                DFS(i,j+x,grid,vis,m,n);
        }
    }
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        ll m = grid.size();
        ll n = grid[0].size();
        vector<vector<ll>> vis(m,vector<ll>(n,0));
        for(ll i=0;i<m;i++)
        {
            if(grid[i][0]==1 and vis[i][0]==0)
                DFS(i,0,grid,vis,m,n);
            if(grid[i][n-1]==1 and vis[i][n-1]==0)
                DFS(i,n-1,grid,vis,m,n);
        }
        for(ll j=0;j<n;j++)
        {
            if(grid[0][j]==1 and vis[0][j]==0)
                DFS(0,j,grid,vis,m,n);
            if(grid[m-1][j]==1 and vis[m-1][j]==0)
                DFS(m-1,j,grid,vis,m,n);
        }
        ll ans = 0;
        for(ll i=0;i<m;i++)
            for(ll j=0;j<n;j++)
                if(grid[i][j]==1 and vis[i][j]==0)
                    ans += 1;
        return ans;
    }
};