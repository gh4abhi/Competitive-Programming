// Problem Link - https://leetcode.com/problems/coin-change-2/

#define ll int

class Solution {
public:
    int change(int amount, vector<int>& coins) {
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
                    dp[j] += dp[j-coins[i]];
                }
            }
        }
        return dp[amount];
    }
};
