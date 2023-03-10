// Problem Link - https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349
#include<bits/stdc++.h>
#define ll long long
ll dp[1001][1001];
ll minPath(vector<vector<int>> &grid, ll i, ll j)
{
    if(i==grid.size()-1 and j==grid[0].size()-1)
        return grid[i][j];
    else if(i>grid.size()-1 or j>grid[0].size()-1)
        return 1e9;
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll one = grid[i][j] + minPath(grid,i+1,j);
    ll two = grid[i][j] + minPath(grid,i,j+1);
    return dp[i][j] = min(one,two);
}

int minSumPath(vector<vector<int>> &grid) {
    memset(dp,-1,sizeof(dp));
    minPath(grid,0,0);
    return (int)dp[0][0];
}