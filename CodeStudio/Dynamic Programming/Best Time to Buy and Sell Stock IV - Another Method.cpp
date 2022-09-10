// Problem Link - https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_1080698?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll int

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<ll> dp(2*k+1,0);
    for(ll i=0;i<2*k;i++)
        dp[i] = 0;
    dp[2*k] = 0;
    for(ll i=n-1;i>=0;i--)
    {
        vector<ll> temp = dp;
        for(ll trans = 0; trans<2*k; trans++)
        {
            if(trans%2==0)
                dp[trans] = max(-prices[i] + temp[trans+1], temp[trans]);
            else
                dp[trans] = max(prices[i] + temp[trans+1], temp[trans]);
        }
    }
    return dp[0];
}


