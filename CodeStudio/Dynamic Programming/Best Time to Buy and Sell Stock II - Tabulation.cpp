// Problem Link - https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<vector>
#define ll long long

long getMaximumProfit(long *values, int n)
{
    vector<vector<ll>> dp(n+1,vector<ll>(2,0));
    dp[n][0] = dp[n][1] = 0;
    for(ll i=n-1;i>=0;i--)
    {
        for(ll buy = 1; buy>=0; buy--)
        {
            if(buy)
                dp[i][buy] = max(-values[i] + dp[i+1][0], dp[i+1][1]);
            else
                dp[i][buy] = max(values[i] + dp[i+1][1], dp[i+1][0]);
        }
    }
    return dp[0][1];
}