// Problem Link - https://leetcode.com/problems/unique-paths-ii/

#define ll int

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<ll>> dp(obstacleGrid.size(),vector<ll>(obstacleGrid[0].size(),0));
        dp[0][0] = 1;
        if(obstacleGrid[0][0]==1)
            return 0;
        for(ll i=0;i<obstacleGrid.size();i++)
        {
            for(ll j=0;j<obstacleGrid[0].size();j++)
            {
                if(obstacleGrid[i][j]==0)
                {
                    if(i==0 and j==0)
                    {
                        dp[i][j] = 1;
                    }
                    else if(i==0)
                    {
                        dp[i][j] = dp[i][j-1];
                    }
                    else if(j==0)
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                }
            }
        }
         return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};