// Problem Link - https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll int

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<ll>> dp(2,vector<ll>(3,0));
    for(ll buy=0;buy<=1;buy++)
        for(ll count = 0; count<=2;count++)
            dp[buy][count] = 0;
    for(ll buy=0;buy<=1;buy++)
        dp[buy][2] = 0;
    for(ll i=n-1;i>=0;i--)
    {
        for(ll buy = 0; buy<=1; buy++)
        {
            vector<vector<ll>> temp = dp;
            for(ll count=0; count<2; count++)
            {
                if(buy)
                    dp[buy][count] = max(-prices[i] + temp[0][count], temp[1][count]);
                else
                    dp[buy][count] = max(prices[i] + temp[1][count+1], temp[0][count]);
            }
        }
    }
    return dp[1][0];
}