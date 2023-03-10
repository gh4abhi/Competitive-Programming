// Problem Link - https://www.codingninjas.com/codestudio/problems/edit-distance_630420?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

int editDistance(string str1, string str2)
{
    ll m = str1.length(), n = str2.length();
    vector<vector<ll>> dp(m+1,vector<ll>(n+1,0));
    for(ll j=0;j<n+1;j++)
        dp[0][j] = j;
    for(ll i=0;i<m+1;i++)
        dp[i][0] = i;
    for(ll i=1;i<m+1;i++)
    {
        for(ll j=1;j<n+1;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
        }
    }
    return dp[m][n];
}