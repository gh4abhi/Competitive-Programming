// Problem Link - https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

bool wildcardMatching(string p, string s)
{
   ll m = s.length(), n = p.length();
   vector<vector<ll>> dp(m+1,vector<ll>(n+1,0));
   dp[0][0] = 1;
    for(ll i=1;i<m+1;i++)
        dp[i][0] = 0;
    for(ll j=1;j<n+1;j++)
    {
        if(p[j-1]!='*')
            break;
        dp[0][j] = 1;
    }
    for(ll i=1;i<m+1;i++)
    {
        for(ll j=1;j<n+1;j++)
        {
            if(s[i-1]==p[j-1] or p[j-1]=='?')
                dp[i][j] = dp[i-1][j-1];
            else if(p[j-1]=='*')
                dp[i][j] = dp[i-1][j] or dp[i][j-1];
            else
                dp[i][j] = 0;
                
        }
    }
    return dp[m][n];
}
