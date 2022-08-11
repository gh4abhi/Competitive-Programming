// Problem Link - https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

long countWaysToMakeChange(int *d, int n, int value)
{
    vector<ll> dp(value+1,0), temp(value+1,0);
    for(ll i=0;i<value+1;i++)
        if(i%d[0]==0)
            dp[i] = 1;
    for(ll i=1;i<n;i++)
    {
        temp = dp;
        for(ll j=0;j<value+1;j++)
        {
            dp[j] = temp[j];
            if(j>=d[i])
                dp[j] += dp[j-d[i]];
        }
    }
    return dp[value];
}