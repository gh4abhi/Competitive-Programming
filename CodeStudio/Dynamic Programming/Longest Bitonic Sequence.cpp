// Problem Link - https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

void lis(vector<ll> &arr, ll n, vector<ll> &dp)
{
    for(ll i=1;i<n;i++)
        for(ll j=i-1;j>=0;j--)
            if(arr[i]>arr[j] and dp[i]<1+dp[j])
                dp[i] = 1+dp[j];
}

int longestBitonicSequence(vector<int>& arr, int n) {
    vector<ll> dp1(n,1), dp2(n,1);
    lis(arr,n,dp1);
    reverse(arr.begin(),arr.end());
    lis(arr,n,dp2);
    ll ans = 1;
    reverse(dp2.begin(),dp2.end());
    for(ll i=0;i<n;i++)
        ans = max(ans,dp1[i]+dp2[i]-1);
    return ans;
} 
