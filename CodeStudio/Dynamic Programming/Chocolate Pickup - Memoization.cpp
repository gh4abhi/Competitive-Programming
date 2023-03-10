// Problem Link - https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?leftPanelTab=0

#define ll int

ll dp[71][71][71];
ll cherryPick(vector<vector<int>>& grid, ll i, ll j1, ll j2)
    {
        if(j1<0 or j1> grid[0].size()-1 or j2<0 or j2>grid[0].size()-1)
            return -1e9;
        if(i==grid.size()-1)
        {
            if(j1==j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        ll maxi = -1e9;
        for(ll j=-1;j<2;j++)
        {
            for(ll k=-1;k<2;k++)
            {
                if(j1==j2)
                    maxi = max(maxi,grid[i][j1] + cherryPick(grid,i+1,j1+j,j2+k));
                else
                    maxi = max(maxi,grid[i][j1] + 
                              grid[i][j2] + cherryPick(grid,i+1,j1+j,j2+k));
                }
        }
        return dp[i][j1][j2] = maxi;
    }
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
        memset(dp,-1,sizeof(dp));
        return (int)cherryPick(grid,0,0,grid[0].size()-1);
}