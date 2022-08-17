// Problem Link - https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int lcs(string s, string t)
{
    ll m = s.length();
    ll n = t.length();
    vector<vector<ll>> dp(m+1,vector<ll>(n+1,0));
    for(ll i=1;i<m+1;i++)
    {
        for(ll j=1;j<n+1;j++)
        {
            if(s[i-1]==t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    ll i = m, j = n;
    ll ind = dp[m][n];
    string str = string(ind,'$');
    while(i>0 and j>0)
    {
        if(s[i-1]==t[j-1])
            str[--ind] = s[i-1], i--, j--;
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    cout<<str;
    return dp[m][n];
}