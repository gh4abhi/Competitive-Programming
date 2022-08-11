// Problem Link - https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

ll countWays(int *d, int n, int value, ll ind, vector<vector<ll>>& dp)
{
    if(ind==0)
    {
        if(value%d[ind]==0)
            return 1;
        return 0;
    }
    if(dp[ind][value]!=-1)
        return dp[ind][value];
    ll notTake = countWays(d,n,value,ind-1,dp);
    ll take = 0;
    if(value-d[ind]>=0)
        take = countWays(d,n,value-d[ind],ind,dp);
    return dp[ind][value] = take + notTake;
}

long countWaysToMakeChange(int *d, int n, int value)
{
    vector<vector<ll>> dp(n,vector<ll>(value+1,-1));
    return countWays(d,n,value,n-1,dp);
}