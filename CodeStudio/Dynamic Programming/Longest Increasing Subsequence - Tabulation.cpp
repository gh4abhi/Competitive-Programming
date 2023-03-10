// Problem Link - https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
    for(ll i=0;i<n+1;i++)
        dp[n][i] = 0;
    for(ll i=n-1;i>=0;i--)
    {
        for(ll j=-1;j<i;j++)
        {
            if(j==-1 or arr[j]<arr[i])
                dp[i][j+1] = max(dp[i][j+1],1+dp[i+1][i+1]);
            dp[i][j+1] = max(dp[i][j+1],dp[i+1][j+1]);
        }
    }
    return dp[0][0];
}
