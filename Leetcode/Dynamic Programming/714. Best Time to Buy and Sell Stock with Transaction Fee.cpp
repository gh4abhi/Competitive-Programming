// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#define ll int

class Solution {
public:
    
    ll maxPro(vector<ll>& prices, ll fee, ll buy, ll i, ll n, vector<vector<ll>> &dp)
    {
        if(i==n)
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy)
            return dp[i][buy] = max(-prices[i] + maxPro(prices,fee,0,i+1,n,dp), maxPro(prices,fee,1,i+1,n,dp));
        return dp[i][buy] = max(prices[i] - fee + maxPro(prices,fee,1,i+1,n,dp), maxPro(prices,fee,0,i+1,n,dp));
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        ll n = prices.size();
        vector<vector<ll>> dp(n,vector<ll>(2,-1));
        return maxPro(prices,fee,1,0,n,dp);
    }
};