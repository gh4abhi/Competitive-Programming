// Problem Link - https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_1080698?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll int

ll maxPro(vector<ll>& prices, ll i, ll buy, ll count, ll k, ll n, vector<vector<vector<ll>>> &dp)
    {
        if(count==k)
            return 0;
        if(i==n)
            return 0;
        if(dp[i][buy][count]!=-1)
            return dp[i][buy][count];
        if(buy)
            return dp[i][buy][count] = max(-prices[i] + maxPro(prices,i+1,0,count,k,n,dp), maxPro(prices,i+1,1,count,k,n,dp));
        return dp[i][buy][count] = max(prices[i] + maxPro(prices,i+1,1,count+1,k,n,dp), maxPro(prices,i+1,0,count,k,n,dp));
    }
    
int maximumProfit(vector<int> &prices, int n, int k)
{
        vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(2,vector<ll>(k+1,-1)));
        return maxPro(prices,0,1,0,k,n,dp);
}
