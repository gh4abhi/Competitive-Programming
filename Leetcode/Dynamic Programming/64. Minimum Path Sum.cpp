// Problem Link - https://leetcode.com/problems/minimum-path-sum/

#define ll int
class Solution {
public:
    
ll minCostPathDP(vector<vector<ll>>& vect)
{
    ll m = vect.size();
    ll n = vect[0].size();
    ll dp[m][n];
    dp[m-1][n-1] = vect[m-1][n-1];
    // Filling last row (right -> left)
    for(ll i = n-2;i>=0;i--)
    {
        dp[m-1][i] = vect[m-1][i] + dp[m-1][i+1];
    }
    // Filling last column (bottom -> top)
    for(ll i = m-2;i>=0;i--)
    {
        dp[i][n-1] = vect[i][n-1] + dp[i+1][n-1];
    }

    for(ll i = m-2; i>=0;i--)
    {
        for(ll j = n-2; j>=0; j--) {

            dp[i][j] = vect[i][j] + min(dp[i+1][j],dp[i][j+1]);
        }
    }
return dp[0][0];

}
    
    int minPathSum(vector<vector<int>>& grid) {
    return minCostPathDP(grid);
    }
};
