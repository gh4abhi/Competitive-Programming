// Problem Link - https://www.codingninjas.com/codestudio/problems/subsequence-counting_3755256?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int
#define MOD 1000000007
ll dp[1000][1000];
ll subCount(string t, string s, ll i, ll j)
{
    if(j<0)
        return 1;
    if(i<0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(t[i]==s[j])
        return dp[i][j] = (subCount(t,s,i-1,j-1) + subCount(t,s,i-1,j))%MOD;
    else
        return dp[i][j] = subCount(t,s,i-1,j)%MOD;
}

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    memset(dp,-1,sizeof(dp));
    return subCount(t,s,lt-1,ls-1);
} 