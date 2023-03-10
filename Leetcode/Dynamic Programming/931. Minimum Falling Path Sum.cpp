// Problem Link - https://leetcode.com/problems/minimum-falling-path-sum/

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
                ll one = 1e9, two = 1e9, three = 1e9;
                one = temp[j];
                if(j>0)
                    two = temp[j-1];
                if(j<n-1)
                    three = temp[j+1];
                dp[j] = grid[i][j] + min(one,min(two,three));
            }
        }
        ll ans = 1e9;
        for(ll i=0;i<n;i++)
            ans = min(ans,dp[i]);
        return ans;
    }
};