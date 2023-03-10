// Problem Link - https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

bool wildcardMatching(string p, string s)
{
   ll m = s.length(), n = p.length();
   vector<ll> dp(n+1,0),temp;
   dp[0] = 1;
    for(ll j=1;j<n+1;j++)
    {
        if(p[j-1]!='*')
            break;
        dp[j] = 1;
    }
    for(ll i=1;i<m+1;i++)
    {
        temp = dp;
        dp[0] = 0;
        for(ll j=1;j<n+1;j++)
        {
            if(s[i-1]==p[j-1] or p[j-1]=='?')
                dp[j] = temp[j-1];
            else if(p[j-1]=='*')
                dp[j] = temp[j] or dp[j-1];
            else
                dp[j] = 0;
        }
    }
    return dp[n];
}
