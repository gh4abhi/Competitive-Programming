// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#define ll int

class Solution {
public:
    
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
    
    int maxProfit(vector<int>& prices) {
        ll n = prices.size();
        vector<vector<ll>> dp(n,vector<ll>(2,-1));
        return maxPro(prices,n,0,1,dp);
    }
};