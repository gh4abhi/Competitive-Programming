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
            ll mini = INT_MAX-1;
            ll sMini = INT_MAX;
            for(ll j=0;j<n;j++)
            {
                if(dp[j]<mini)
                    sMini = mini, mini = dp[j];
                else
                    sMini = min(sMini,dp[j]);
            }
           for(ll j=0;j<n;j++)
           {
               if(dp[j]==mini)
                   dp[j] = sMini + grid[i][j];
                else
                    dp[j] = mini + grid[i][j];
           }
        }
        ll ans = 1e9;
        for(ll i=0;i<n;i++)
            ans = min(ans,dp[i]);
        return ans;
    }
};