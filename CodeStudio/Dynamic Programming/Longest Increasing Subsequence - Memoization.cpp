// Problem Link - https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

ll lis(ll arr[], ll i, ll pre, ll n, vector<vector<ll>> &dp)
{
    if(i==n)
        return 0;
    ll ans = 0;
    if(dp[i][pre+1]!=-1)
        return dp[i][pre+1];
    if(pre==-1 or arr[pre]<arr[i])
        ans = 1 + lis(arr,i+1,i,n,dp);
    return dp[i][pre+1] = max(ans,lis(arr,i+1,pre,n,dp));
    
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<ll>> dp(n,vector<ll>(n+1,-1));
    return lis(arr,0,-1,n,dp);
}
