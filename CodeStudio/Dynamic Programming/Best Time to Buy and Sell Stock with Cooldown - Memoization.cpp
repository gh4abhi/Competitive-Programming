// Problem Link - https://www.codingninjas.com/codestudio/problems/highway-billboards_3125969?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll int
    
    ll maxPro(vector<ll>& prices, ll n, ll i, ll buy, vector<vector<ll>> &dp)
    {
        if(i>=n)
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy)
            return dp[i][buy] = max(-prices[i] + maxPro(prices,n,i+1,0,dp), maxPro(prices,n,i+1,1,dp));
        return dp[i][buy] = max(prices[i] + maxPro(prices,n,i+2,1,dp), maxPro(prices,n,i+1,0,dp));
    }

int stockProfit(vector<int> &prices){
           ll n = prices.size();
        vector<vector<ll>> dp(n,vector<ll>(2,-1));
        return maxPro(prices,n,0,1,dp);
}