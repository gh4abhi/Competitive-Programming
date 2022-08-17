// Problem Link - https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int lcs(string s, string t)
{
    ll m = s.length();
    ll n = t.length();
    vector<ll> dp(n+1,0);
    vector<ll> temp(n+1,0);
    for(ll i=1;i<m+1;i++)
    {
        temp = dp;
        for(ll j=1;j<n+1;j++)
        {
            if(s[i-1]==t[j-1])
                dp[j] = 1 + temp[j-1];
            else
                dp[j] = max(dp[j-1],temp[j]);
        }
    }
    return dp[n];
}