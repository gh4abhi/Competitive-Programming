// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#define ll int

class Solution {
public:
    
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
    
    int maxProfit(int k, vector<int>& prices) {
        ll n = prices.size();
        vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(2,vector<ll>(k+1,-1)));
        return maxPro(prices,0,1,0,k,n,dp);
    }
};