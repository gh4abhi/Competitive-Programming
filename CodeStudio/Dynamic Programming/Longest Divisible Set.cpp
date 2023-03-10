// Problem Link - https://www.codingninjas.com/codestudio/problems/divisible-set_3754960?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

vector<int> divisibleSet(vector<int> &arr){
    ll n = arr.size();
    vector<ll> dp(n,1);
    vector<ll> par(n);
    for(ll i=0;i<n;i++)
        par[i] = i;
    sort(arr.begin(),arr.end());
    vector<ll> ans;
    for(ll i=0;i<n;i++)
        for(ll j=0;j<i;j++)
            if(arr[i]%arr[j]==0)
                if(dp[i]<1+dp[j])
                    dp[i] = 1 + dp[j], par[i] = j;
    ll ind = n-1;
    ll maxi = INT_MIN;
    for(ll i=0;i<n;i++)
        if(maxi<dp[i])
            ind = i, maxi = dp[i];
    ans.push_back(arr[ind]);
    while(par[ind]!=ind)
    {
        ind = par[ind];
        ans.push_back(arr[ind]);
    }
    return ans;
}