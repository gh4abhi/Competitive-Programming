// Problem Link - https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll int

ll maxPro(vector<ll> &prices, ll n, ll count, ll i, ll buy, vector<vector<vector<ll>>> &dp)
{
    if(i==n)
        return 0;
    if(count==2)
        return 0;
    if(dp[i][buy][count]!=-1)
        return dp[i][buy][count];
    if(buy)
        return dp[i][buy][count] = max(-prices[i] + maxPro(prices,n,count,i+1,0,dp), maxPro(prices,n,count,i+1,1,dp));
    return dp[i][buy][count] = max(prices[i] + maxPro(prices,n,count+1,i+1,1,dp), maxPro(prices,n,count,i+1,0,dp));
}

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(2,vector<ll>(3,-1)));
    return maxPro(prices,n,0,0,1,dp);
}