// Problem Link - https://www.codingninjas.com/codestudio/problems/loot-houses_630510?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int maxMoneyLooted(vector<int> &houses, int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return houses[0];
    ll dp[n];
    memset(dp,0,sizeof(dp));
    dp[0] = houses[0];
    dp[1] = max(dp[0],houses[1]);
    for(ll i=2;i<n;i++)
    {
        dp[i] = max(dp[i-1],dp[i-2]+houses[i]);        
    }
    return max(dp[n-1],dp[n-2]);
}