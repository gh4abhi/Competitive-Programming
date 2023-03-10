// Problem Link - https://leetcode.com/problems/detect-cycles-in-2d-grid/

#define ll int

class Solution {
public:
    bool containsCycleHelper(vector<vector<char>>& grid, vector<vector<bool>>& visited, ll preR , ll preC, ll i, ll j)
    {
        visited[i][j] = true;
        ll ans = false;
        if(i>0 and grid[i][j]==grid[i-1][j])
        {
            if(visited[i-1][j]==false)
            {   if(containsCycleHelper(grid, visited, i, j, i-1, j))
                {
                    return true;
                }
			}    
            else if(visited[i-1][j]==true and (i-1!=preR or j!=preC))
               {
                    return true;
                }    
        }
        if(i<grid.size()-1 and grid[i][j]==grid[i+1][j])
        {
            if(visited[i+1][j]==false)
            {  if(containsCycleHelper(grid, visited, i, j, i+1, j))
                    {
                    return true;
                }}    
            else if(visited[i+1][j]==true and (i+1!=preR or j!=preC))
                {
                    return true;
                }    
        }
        if(j>0 and grid[i][j]==grid[i][j-1])
        {
            if(visited[i][j-1]==false)
            {  if(containsCycleHelper(grid, visited, i, j, i, j-1))
                    {
                    return true;
                }    }
            else if(visited[i][j-1]==true and (i!=preR or j-1!=preC))
                {
                    return true;
                }    
        }
        if(j<grid[0].size()-1 and grid[i][j]==grid[i][j+1])
        {
            cout<<visited[i][j+1]<<endl;
            if(visited[i][j+1]==false)
            { if(containsCycleHelper(grid, visited, i, j, i, j+1))
                {
                    return true;
                }   } 
            else if(visited[i][j+1]==true and (i!=preR or j+1!=preC))
            {
                return true;
            }
        }
        
        return ans;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        ll m = grid.size();
        ll n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        bool ans = false;
        for(ll i=0;i<m;i++)
            for(ll j=0;j<n;j++)
                if(!visited[i][j])
                 ans  = ans or containsCycleHelper(grid, visited, -1,-1,i,j);
    return ans;
    }
};
