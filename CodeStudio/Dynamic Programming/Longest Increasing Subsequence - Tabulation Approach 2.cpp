// Problem Link - https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<ll> dp(n,1);
    for(ll i=0;i<n;i++)
        for(ll j=i-1;j>=0;j--)
            if(arr[i]>arr[j])
                dp[i] = max(dp[i],1+dp[j]);
    ll ans = INT_MIN;
    for(auto i:dp)
        ans = max(ans,i);
    return ans;
}
