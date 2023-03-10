// Problem Link - https://leetcode.com/problems/longest-arithmetic-subsequence/

#define ll int

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        ll n = nums.size();
        ll ans = 0;
        vector<vector<ll>> dp(n+1,vector<ll>(1001,1));
        for(ll i=n-1;i>=0;i--)
        {
            for(ll j=i-1;j>=0;j--)
            {
                dp[j][500+nums[i]-nums[j]] = max(dp[j][500+nums[i]-nums[j]],1+dp[i][500+nums[i]-nums[j]]);
                ans = max(ans,dp[j][500+nums[i]-nums[j]]);
            }
        }
        return ans;
    }
};