// Problem Link - https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int lcs(string &s, string &t){
    ll m = s.length(), n = t.length();
    vector<vector<ll>> dp(m+1,vector<ll>(n+1,0));
    ll ans = -1e9;
    for(ll i=1;i<m+1;i++)
        for(ll j=1;j<n+1;j++)
            if(s[i-1]==t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1], ans = max(ans,dp[i][j]);
    return max(ans,0);
}