// Problem Link - https://www.codingninjas.com/codestudio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

ll lcs(string a, string b, ll ind1, ll ind2, vector<vector<ll>> &dp)
{
    if(ind1<0 or ind2<0)
        return 0;
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    if(a[ind1]==b[ind2])
        return dp[ind1][ind2] = 1 + lcs(a,b,ind1-1,ind2-1,dp);
    else
        return dp[ind1][ind2] = max(lcs(a,b,ind1-1,ind2,dp),lcs(a,b,ind1,ind2-1,dp));
}

int canYouMake(string &str, string &ptr)
{
    vector<vector<ll>> dp(str.length()+1,vector<ll>(ptr.length()+1,-1));
    return str.length() + ptr.length() - 2*lcs(str,ptr,str.length()-1,ptr.length()-1,dp);
}