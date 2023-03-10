// Problem Link - https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<vector>
#define ll long long

long getMaximumProfit(long *values, int n)
{
    vector<ll> dp(2,0);
    dp[0] = dp[1] = 0;
    for(ll i=n-1;i>=0;i--)
    {
        vector<ll> temp = dp;
        for(ll buy = 1; buy>=0; buy--)
        {
            if(buy)
                dp[buy] = max(-values[i] + temp[0], temp[1]);
            else
                dp[buy] = max(values[i] + temp[1], temp[0]);
        }
    }
    return dp[1];
}