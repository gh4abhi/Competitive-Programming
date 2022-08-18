// Problem Link - https://www.codingninjas.com/codestudio/problems/longest-palindromic-subsequence_842787?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

ll lcs(string s, string t)
{
    ll m = s.length(), n = t.length();
    vector<ll> dp(m+1,0), temp(m+1);
    for(ll i=1;i<m+1;i++)
    {
        temp = dp;
        for(ll j=1;j<n+1;j++)
        {
            if(s[i-1]==t[j-1])
                dp[j] = 1 + temp[j-1];
            else
                dp[j] = max(temp[j],dp[j-1]);
        }
    }
    return dp[n];
}

int longestPalindromeSubsequence(string s)
{
    string t = s;
    reverse(t.begin(),t.end());
    return lcs(s,t);
}