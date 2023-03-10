// Problem Link - https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll int

int maxProfit(vector<int>& prices, int n)
{
    vector<ll> dp(5,0);
    for(ll i=0;i<4;i++)
        dp[i] = 0;
    dp[4] = 0;
    for(ll i=n-1;i>=0;i--)
    {
        vector<ll> temp = dp;
        for(ll trans = 0; trans<4; trans++)
        {
            if(trans%2==0)
                dp[trans] = max(-prices[i] + temp[trans+1], temp[trans]);
            else
                dp[trans] = max(prices[i] + temp[trans+1], temp[trans]);
        }
    }
    return dp[0];
}