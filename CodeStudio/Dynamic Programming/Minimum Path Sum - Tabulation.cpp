// Problem Link - https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349

#include<bits/stdc++.h>
#define ll long long
int minSumPath(vector<vector<int>> &grid) {
    ll m = grid.size();
    ll n = grid[0].size();
    ll dp[m][n];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<m;i++)
        for(ll j=0;j<n;j++)
        {
            if(i==0 and j==0)
                dp[i][j] = grid[i][j];
            else
            {
                dp[i][j] = 1e9;
                if(i>0)
                    dp[i][j] = min(dp[i-1][j],dp[i][j]);
                if(j>0)
                    dp[i][j] = min(dp[i][j-1],dp[i][j]);
                dp[i][j] +=grid[i][j];
            }
        }
    return dp[m-1][n-1];
}