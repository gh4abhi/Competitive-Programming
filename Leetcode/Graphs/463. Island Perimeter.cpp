// Problem Link - https://leetcode.com/problems/island-perimeter/

#define ll int

class Solution {
public:
    
    ll perimeter = 0;
    
    void dfs(vector<vector<int>>& grid, ll i, ll j)
    {
        grid[i][j] = -1;
        ll above = 0, left = 0, right = 0, down = 0;
        if(i>0 and grid[i-1][j]==1)
        {
            dfs(grid, i-1, j);
        }
        else
        {
            if(i==0 or (i>0 and grid[i-1][j]==0))
                above = 1;
        }
        if(j>0 and grid[i][j-1]==1)
        {
            dfs(grid,  i,  j-1);
        }
        else
        {
            if(j==0 or (j>0 and grid[i][j-1]==0))
                left = 1;
        }
        if(i<grid.size()-1 and grid[i+1][j]==1)
        {
            dfs(grid, i+1, j);
        }
        else
        {
            if(i==grid.size()-1 or (i<grid.size()-1 and grid[i+1][j]==0))
                down = 1;
        }
        if(j<grid[0].size()-1 and grid[i][j+1]==1)
        {
            dfs(grid, i,j+1);
        }
        else
        {
            if(j==grid[0].size()-1 or (j<grid[0].size()-1 and grid[i][j+1]==0))
                right = 1;
        }
        
        if(above)
            perimeter += 1;
        if(down)
            perimeter += 1;
        if(right)
            perimeter += 1;
        if(left)
            perimeter += 1;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        for(ll i=0;i<grid.size();i++)
        {
            for(ll j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid, i, j);
                    return perimeter;
                }
            }
        }
        return 0;
    }
};