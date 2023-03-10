// Problem Link - https://leetcode.com/problems/pascals-triangle/

#define ll int

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<ll>> dp(numRows);
        dp[0].push_back(1);
        for(ll i=1;i<numRows;i++)
        {
            for(ll j=0;j<i+1;j++)
            {
                if(j==0)
                {
                    dp[i].push_back(dp[i-1][j]);
                    continue;
                }
                else if(j==i)
                {
                    dp[i].push_back(dp[i-1][j-1]);
                    continue;
                }
                dp[i].push_back(dp[i-1][j-1]+dp[i-1][j]);
            }
        }
        return dp;
    }
};
