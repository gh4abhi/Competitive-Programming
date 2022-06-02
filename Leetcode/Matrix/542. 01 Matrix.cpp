// Problem Link - https://leetcode.com/problems/01-matrix/

#define ll int

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<ll>> dp(mat.size(),vector<ll>(mat[0].size(),1e5));
        for(ll i=0;i<mat.size();i++)
        {
            if(mat[i][0]==0)
                dp[i][0] = 0;
            for(ll j=1;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = min(dp[i][j],1+dp[i][j-1]);
            }
        }
        for(ll i=0;i<mat.size();i++)
        {
            if(mat[i][mat[0].size()-1]==0)
                dp[i][mat[0].size()-1] = 0;
            for(ll j=mat[0].size()-2;j>=0;j--)
            {
                if(mat[i][j]==0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = min(dp[i][j],1+dp[i][j+1]);
            }
        }
        for(ll j=0;j<mat[0].size();j++)
        {
            if(mat[mat.size()-1][j]==0)
                dp[mat.size()-1][j] = 0;
            for(ll i= mat.size()-2;i>=0;i--)
            {
                if(mat[i][j]==0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = min(dp[i][j],1+dp[i+1][j]);
            }
        }
        for(ll j=0;j<mat[0].size();j++)
        {
            if(mat[0][j]==0)
                dp[0][j] = 0;
            for(ll i=1;i<mat.size();i++)
            {
                if(mat[i][j]==0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = min(dp[i][j],1+dp[i-1][j]);
            }
        }
        return dp;
    }
};