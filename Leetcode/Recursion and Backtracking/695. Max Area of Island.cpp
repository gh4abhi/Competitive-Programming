#define ll int 

class Solution {
public:
    
    ll islandArea(vector<vector<int>>& grid, vector<vector<bool>>& visited, ll i, ll j, ll n, ll m)
    {
        ll sum = 1;
        visited[i][j] = true;
        if(i<n-1 and visited[i+1][j]==false and grid[i+1][j]==1)
            sum+=islandArea(grid, visited, i+1,j,n,m);
        if(i>0 and visited[i-1][j]==false and grid[i-1][j]==1)
            sum+=islandArea(grid, visited, i-1,j,n,m);
        if(j<m-1 and visited[i][j+1]==false and grid[i][j+1]==1)
            sum+=islandArea(grid, visited, i,j+1,n,m);
        if(j>0 and visited[i][j-1]==false and grid[i][j-1]==1)
            sum+=islandArea(grid, visited, i,j-1,n,m);
        return sum;    
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ll n = grid.size();
        ll m = grid[0].size();
        ll maxi = INT_MIN;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                if(grid[i][j]==1 and visited[i][j]==false)
                    maxi = max(maxi,islandArea(grid, visited, i, j, n, m));
            }
        }
        if(maxi==INT_MIN)
            return 0;
        return maxi;
    }
};
