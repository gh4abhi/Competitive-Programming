// Problem Link - https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

long countWaysToMakeChange(int *d, int n, int value)
{
    vector<vector<ll>> dp(n,vector<ll>(value+1,0));
    for(ll i=0;i<value+1;i++)
        if(i%d[0]==0)
            dp[0][i] = 1;
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<value+1;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=d[i])
                dp[i][j] += dp[i][j-d[i]];
        }
    }
    return dp[n-1][value];
}