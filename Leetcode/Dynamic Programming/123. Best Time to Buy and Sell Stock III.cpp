// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#define ll int

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    ll n = prices.size();
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
};