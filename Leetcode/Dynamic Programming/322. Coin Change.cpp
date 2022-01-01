// Problem Link - https://leetcode.com/problems/coin-change/

#define ll int

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        ll dp[amount+1];
        for(ll i=0;i<amount+1;i++)
        {
            dp[i] = 0;
        }
        dp[0] = 1;
        for(ll i=0;i<coins.size();i++)
        {
            for(ll j=coins[i];j<amount+1;j++)
            {
                if(dp[j-coins[i]]!=0)
                {
                    if(dp[j]==0)
                        dp[j] = 1 + dp[j-coins[i]];
                    else
                        dp[j] = min(dp[j],1 + dp[j-coins[i]]);
                }
            }
        }
        if(dp[amount]==0)
        {
            return -1;
        }
        return dp[amount]-1;
    }
};
