// Problem Link - https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<ll> dp(n,1);
    vector<ll> par(n);
    for(ll i=0;i<n;i++)
        par[i] = i;
    for(ll i=0;i<n;i++)
        for(ll j=i-1;j>=0;j--)
            if(arr[i]>arr[j])
                if(dp[i]<1+dp[j])
                    dp[i] = 1 + dp[j], par[i] = j;
    ll ans = INT_MIN;
    ll ind = n-1;
    for(ll i=0;i<n;i++)
        if(ans<dp[i])
            ans = dp[i], ind = i;
    vector<ll> lis;
    lis.push_back(arr[ind]);
    while(par[ind]!=ind)
    {
        ind = par[ind];
        lis.push_back(arr[ind]);
    }
    reverse(lis.begin(),lis.end());
    for(auto i:lis)
        cout<<i<<" ";
    return ans;
}
