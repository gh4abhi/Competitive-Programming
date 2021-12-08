// Problem link - https://leetcode.com/problems/path-with-maximum-gold/

#define ll int

class Solution {
public:
    
    ll getMaximumGoldHelper(vector<vector<int>>& grid, vector<vector<bool>>& visited, ll i, ll j, ll n, ll m)
    {
        
        
        if(i>n-1 or j>m-1 or i<0 or j<0 or visited[i][j] or grid[i][j]==0)
        {
            return 0;
        }
        
        visited[i][j] = true;

        
        ll up = getMaximumGoldHelper(grid, visited, i-1, j, n, m);
        ll down = getMaximumGoldHelper(grid, visited, i+1, j, n, m);
        ll left = getMaximumGoldHelper(grid, visited, i, j-1, n, m);
        ll right = getMaximumGoldHelper(grid, visited, i, j+1, n, m);
        
        visited[i][j] = false;
        
        return grid[i][j] + max(up,max(down,max(left,right)));
        
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
     vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        ll overAllMax = 0;
        ll n = grid.size();
        ll m = grid[0].size();
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                ll maxi = getMaximumGoldHelper(grid, visited, i, j, n, m);
                overAllMax = max(overAllMax, maxi);
            }
        }
        return overAllMax;
    }
};
