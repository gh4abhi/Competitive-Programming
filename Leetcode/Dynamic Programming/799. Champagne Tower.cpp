// Problem Link - https://leetcode.com/problems/champagne-tower/

#define ll int

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        ll k = poured;
        vector<vector<double>> dp(100,vector<double>(100,0));
        if(k==0)
            return 0.0;
        dp[0][0] = k;
        ll val = 2;
        for(ll i=1;i<100;i++)
        {
            for(ll j=0;j<val;j++)
            {
                if(j==0)
                {
                    if(dp[i-1][j]>1)
                    dp[i][j] = (dp[i-1][j]-1)/2;
                }
                else if(j==val-1)
                {
                    if(dp[i-1][j-1]>1)
                    dp[i][j] = (dp[i-1][j-1]-1)/2;
                }
                else
                {
                    if(dp[i-1][j-1]>1)
                    dp[i][j] += (dp[i-1][j-1]-1)/2;
                    if(dp[i-1][j]>1)
                        dp[i][j] += (dp[i-1][j]-1)/2;
                }
            }
            val++;
        }
        return min(dp[query_row][query_glass],1.0);
    }
};