// Problem Link - https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349

#include<bits/stdc++.h>
#define ll long long
int minSumPath(vector<vector<int>> &grid) {
    ll m = grid.size();
    ll n = grid[0].size();
    vector<ll> dp(n,1e9);
    for(ll i=0;i<m;i++)
        for(ll j=0;j<n;j++)
        {
            if(i==0 and j==0)
                dp[0] = grid[i][j];
            else if(j==0)
                dp[j] +=grid[i][j];
            else
            {
                dp[j] = min(dp[j],dp[j-1]);
                dp[j] += grid[i][j];
            }
        }
    return dp[n-1];
}