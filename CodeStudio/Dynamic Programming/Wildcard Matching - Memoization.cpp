// Problem Link - https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

bool match(string &s, string &p , ll i, ll j, vector<vector<ll>>& dp)
{
    if(i<0 and j<0)
        return true;
    if(j<0)
        return false;
    if(i<0)
    {
        for(ll k=0;k<=j;k++)
            if(p[k]!='*')
                return false;
        return true;
    }
    if(dp[i][j]!=-1)
       return dp[i][j];
    if(s[i]==p[j] or p[j]=='?')
        return dp[i][j] = match(s,p,i-1,j-1,dp);
    else if(p[j]=='*')
        return dp[i][j] = match(s,p,i-1,j,dp) or match(s,p,i,j-1,dp);
    return false;
}

bool wildcardMatching(string pattern, string text)
{
   ll m = text.length(), n = pattern.length();
    vector<vector<ll>> dp(m,vector<ll>(n,-1));
   return match(text,pattern,m-1,n-1,dp);
}
