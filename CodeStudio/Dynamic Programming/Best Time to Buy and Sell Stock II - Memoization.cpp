// Problem Link - https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<vector>
#define ll long long

ll getMax(long* values, ll n, ll buy, ll i, vector<vector<ll>> &dp)
{
    if(i==n)
        return 0;
    if(dp[i][buy]!=-1)
        return dp[i][buy];
    if(buy)
        return dp[i][buy] = max(-values[i] + getMax(values,n,0,i+1,dp), getMax(values,n,1,i+1,dp));
    return dp[i][buy] = max(values[i]+getMax(values,n,1,i+1,dp), getMax(values,n,0,i+1,dp));
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<ll>> dp(n,vector<ll>(2,-1));
    return getMax(values,n,1,0,dp);
}