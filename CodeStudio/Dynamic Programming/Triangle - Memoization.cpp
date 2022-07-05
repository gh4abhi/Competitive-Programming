// Problem Link - https://www.codingninjas.com/codestudio/problems/triangle_1229398?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int
ll dp[1001][1001];
ll minPath(vector<vector<int>> &grid, ll i, ll j)
{
    if(i==grid.size()-1)
        return grid[i][j];
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll one = grid[i][j] + minPath(grid,i+1,j);
    ll two = grid[i][j] + minPath(grid,i+1,j+1);
    return dp[i][j] = min(one,two);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    memset(dp,-1,sizeof(dp));
    return minPath(triangle,0,0);
}