// Problem Link - https://leetcode.com/problems/maximal-square/

#define ll int
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    ll m = matrix.size();
    ll n = matrix[0].size();

    ll dp[m][n];
    ll maxi = 0;

    for(ll i=m-1;i>=0;i--)
    {
        for(ll j=n-1;j>=0;j--)
        {
            if(i==m-1)
            {
                dp[i][j] = matrix[i][j]-'0';
            }
            else if(j==n-1)
            {
                 dp[i][j] = matrix[i][j]-'0';
                
            }
            else
            {
                dp[i][j] = matrix[i][j] - '0';
                if(dp[i][j]==1) {
                dp[i][j] = 1 + min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
                }            
            }
                maxi = max(maxi,dp[i][j]*dp[i][j]);
        }
    }
return maxi;
    }
};
