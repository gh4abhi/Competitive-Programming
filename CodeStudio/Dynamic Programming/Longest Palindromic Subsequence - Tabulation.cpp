// Problem Link - https://www.codingninjas.com/codestudio/problems/longest-palindromic-subsequence_842787?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

ll lcs(string s, string t)
{
    ll m = s.length(), n = t.length();
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
    return dp[m][n];
}

int longestPalindromeSubsequence(string s)
{
    string t = s;
    reverse(t.begin(),t.end());
    return lcs(s,t);
}