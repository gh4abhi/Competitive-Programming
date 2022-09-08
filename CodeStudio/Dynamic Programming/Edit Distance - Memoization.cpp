// Problem Link - https://www.codingninjas.com/codestudio/problems/edit-distance_630420?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

ll editDis(string str1, string str2, ll i, ll j,vector<vector<ll>> &dp)
{
    if(j<0)
        return i+1;
    if(i<0)
        return j+1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(str1[i]==str2[j])
        return dp[i][j] = editDis(str1,str2,i-1,j-1,dp);
    else
        return dp[i][j] = 1 + min({editDis(str1,str2,i-1,j,dp),editDis(str1,str2,i-1,j-1,dp),editDis(str1,str2,i,j-1,dp)});
}

int editDistance(string str1, string str2)
{
    ll m = str1.length(), n = str2.length();
    vector<vector<ll>> dp(m,vector<ll>(n,-1));
    return (int)editDis(str1,str2,m-1,n-1,dp);
}