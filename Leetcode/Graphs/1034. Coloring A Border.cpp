// Problem Link - https://leetcode.com/problems/coloring-a-border/

#define ll int

class Solution {
public:
    
    void dfs(vector<vector<ll>>&grid, ll i ,ll j, vector<vector<bool>>& vis, ll color, ll cur)
    {
        ll above = 0, down = 0, right = 0, left = 0;
        vis[i][j] = true;
        if(i>0 and grid[i-1][j]==cur and !vis[i-1][j])
            dfs(grid, i-1, j, vis, color, cur);
        else if(i==0 or (i>0 and (grid[i-1][j]!=cur and !vis[i-1][j]))) above = 1;
        if(j>0 and grid[i][j-1]==cur and !vis[i][j-1])
            dfs(grid, i, j-1, vis, color, cur);
        else if(j==0 or (j>0 and (grid[i][j-1]!=cur and !vis[i][j-1]))) left = 1;
        if(i<grid.size()-1 and grid[i+1][j]==cur and !vis[i+1][j])
            dfs(grid, i+1, j, vis, color, cur);
        else if(i==grid.size()-1 or (i<grid.size()-1 and (grid[i+1][j]!=cur and !vis[i+1][j]))) down = 1;
        if(j<grid[0].size()-1 and grid[i][j+1]==cur and !vis[i][j+1])
            dfs(grid, i, j+1, vis, color, cur);
        else if(j==grid[0].size()-1 or (j<grid[0].size()-1 and (grid[i][j+1]!=cur and !vis[i][j+1]))) right = 1;
        if(above or down or left or right)
            grid[i][j] = color;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(),false));
        dfs(grid, row, col, vis, color, grid[row][col]);
        return grid;
    }
};