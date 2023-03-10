// Problem Link - https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll int

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(2,vector<ll>(3,0)));
    for(ll buy=0;buy<=1;buy++)
        for(ll count = 0; count<=2;count++)
            dp[n][buy][count] = 0;
    for(ll i=0;i<n;i++)
        for(ll buy=0;buy<=1;buy++)
            dp[i][buy][2] = 0;
    for(ll i=n-1;i>=0;i--)
    {
        for(ll buy = 0; buy<=1; buy++)
        {
            for(ll count=0; count<2; count++)
            {
                if(buy)
                    dp[i][buy][count] = max(-prices[i] + dp[i+1][0][count], dp[i+1][1][count]);
                else
                    dp[i][buy][count] = max(prices[i] + dp[i+1][1][count+1], dp[i+1][0][count]);
            }
        }
    }
    return dp[0][1][0];
}