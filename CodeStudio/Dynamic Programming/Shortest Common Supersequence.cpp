// Problem Link - https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

string shortestSupersequence(string a, string b)
{
    ll m = a.length();
    ll n = b.length();
    vector<vector<ll>> dp(m+1,vector<ll>(n+1,0));
    for(ll i=1;i<m+1;i++)
    {
        for(ll j=1;j<n+1;j++)
        {
            if(a[i-1]==b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    ll i = m, j = n;
    string ans = "";
    while(i>0 and j>0)
    {
        if(a[i-1]==b[j-1])
            ans += a[i-1],i--,j--;
        else if(dp[i-1][j]>dp[i][j-1])
            ans += a[i-1],i--;
        else
            ans += b[j-1],j--;
    }
    while(i>0)
        ans += a[i-1],i--;
    while(j>0)
        ans += b[j-1],j--;
    reverse(ans.begin(),ans.end());
    return ans;
}