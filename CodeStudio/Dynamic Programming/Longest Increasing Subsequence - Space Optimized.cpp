// Problem Link - https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<ll> dp(n+1), temp(n+1);
    for(ll i=0;i<n+1;i++)
        dp[i] = 0;
    for(ll i=n-1;i>=0;i--)
    {
        temp = dp;
        for(ll j=-1;j<i;j++)
        {
            if(j==-1 or arr[j]<arr[i])
                dp[j+1] = max(dp[j+1],1+temp[i+1]);
            dp[j+1] = max(dp[j+1],temp[j+1]);
        }
    }
    return dp[0];
}
