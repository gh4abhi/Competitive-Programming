// Problem Link - https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

int findNumberOfLIS(vector<int> &arr)
{
    ll n = arr.size();
    vector<ll> dp(n,0);
    vector<ll> count(n,1);
    ll maxi = INT_MIN;
    for(ll i=0;i<n;i++)
    {
        dp[i] = 1;
        for(ll j=i-1;j>=0;j--)
        {
            if(arr[j]<arr[i] and dp[i]<1+dp[j])
                dp[i] = 1 + dp[j], count[i] = count[j];
            else if(arr[j]<arr[i] and dp[i]==1+dp[j])
                count[i] += count[j];
        }
        maxi = max(maxi,dp[i]);
    }
    ll ans = 0;
    for(ll i=0;i<n;i++)
        if(dp[i]==maxi)
            ans += count[i];
    return ans;
}