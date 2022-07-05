// Problem Link - https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

#include<bits/stdc++.h>
#define ll int
int getMaxPathSum(vector<vector<int>> &matrix)
{
    ll m = matrix.size();
    ll n = matrix[0].size();
    ll dp[m][n];
    for(ll i=0;i<n;i++)
        dp[0][i] = matrix[0][i];
    for(ll i=1;i<m;i++)
    {
        for(ll j=0;j<n;j++)
        {
            ll one = -1e9, two = -1e9, three = -1e9;
            one = dp[i-1][j];
            if(j-1>=0)
                two = dp[i-1][j-1];
            if(j+1<n)
                three = dp[i-1][j+1];
            dp[i][j] = matrix[i][j] + max(one,max(two,three));
        }
    }
    ll ans = -1e9;
    for(ll i=0;i<n;i++)
        ans = max(ans,dp[m-1][i]);
    return ans;
}