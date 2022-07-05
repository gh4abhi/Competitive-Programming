// Problem Link - https://leetcode.com/problems/minimum-falling-path-sum-ii/

#define ll int
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        ll m = grid.size();
        ll n = grid[0].size();
        vector<ll> dp(n);
        for(ll i=0;i<n;i++)
            dp[i] = grid[0][i];
        for(ll i=1;i<m;i++)
        {
            vector<ll> temp = dp;
           for(ll j=0;j<n;j++)
           {
               ll val = 1e9;
               for(ll k=0;k<n;k++)
                   if(k!=j)
                       val = min(val,temp[k]);
               dp[j] = grid[i][j] + val;
           }
        }
        ll ans = 1e9;
        for(ll i=0;i<n;i++)
            ans = min(ans,dp[i]);
        return ans;
    }
};