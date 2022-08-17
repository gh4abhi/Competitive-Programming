// Problem Link - https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

ll lcsM(string s, string t, ll ind1, ll ind2,vector<vector<ll>> &dp)
{
    if(ind1<0 or ind2<0)
        return 0;
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    if(s[ind1]==t[ind2])
        return dp[ind1][ind2] = 1 + lcsM(s,t,ind1-1,ind2-1,dp);
    return dp[ind1][ind2] = max(lcsM(s,t,ind1-1,ind2,dp),lcsM(s,t,ind1,ind2-1,dp));
}

int lcs(string s, string t)
{
    ll m = s.length();
    ll n = t.length();
    vector<vector<ll>> dp(m,vector<ll>(n,-1));
    return lcsM(s,t,m-1,n-1,dp);
}