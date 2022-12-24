// Problem Link - https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

#define ll int

class Solution {
  public:
    
    void DFS(ll i, ll j, vector<vector<ll>> &grid, vector<pair<ll,ll>> &vect, vector<vector<ll>> &vis, ll a, ll b)
    {
        ll m = grid.size();
        ll n = grid[0].size();
        vis[i][j] = 1;
        vect.push_back({i-a,j-b});
        for(auto x:{-1,1})
        {
            if(i+x>=0 and i+x<m and grid[i+x][j]==1 and vis[i+x][j]==0)
                DFS(i+x,j,grid,vect,vis,a,b);
            if(j+x>=0 and j+x<n and grid[i][j+x]==1 and vis[i][j+x]==0)
                DFS(i,j+x,grid,vect,vis,a,b);
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        ll m = grid.size();
        ll n = grid[0].size();
        set<vector<pair<ll,ll>>> s;
        vector<vector<ll>> vis(m,vector<ll>(n,0));
        for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(vis[i][j]==0 and grid[i][j]==1)
                {
                    vector<pair<ll,ll>> vect;
                    DFS(i,j,grid,vect,vis,i,j);
                    s.insert(vect);
                }
            }
        }
        return s.size();
    }
};
