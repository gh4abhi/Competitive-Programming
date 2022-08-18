// Problem Link - https://leetcode.com/problems/maximum-length-of-repeated-subarray/

#define ll int

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        ll m = nums1.size(), n = nums2.size();
        vector<vector<ll>> dp(m+1,vector<ll>(n+1,0));
        ll ans = -1e9;
        for(ll i=1;i<m+1;i++)
            for(ll j=1;j<n+1;j++)
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1], ans = max(ans,dp[i][j]);
        return max(0,ans);
    }
};