// Problem Link - https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

bool subsetSumToK(int n, int target, vector<int> &arr) {
    bool dp[n][target+1];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<n;i++)
        dp[i][0] = 1;
    dp[0][arr[0]] = 1;
    for(ll i=1;i<n;i++)
    {
        for(ll j=1;j<target+1;j++)
        {
            dp[i][j] = dp[i][j] or dp[i-1][j];
            if(arr[i]<=j)
            dp[i][j] = dp[i][j] or dp[i-1][j-arr[i]];
        }
    }
    return dp[n-1][target];
}