// Problem Link - https://leetcode.com/problems/longest-increasing-subsequence/

#define ll int

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ll ans = 1; 
        vector<ll> dp(nums.size(),1);
        for(ll i=1;i<nums.size();i++)
            for(ll j=0;j<i;j++)
                if(nums[j]<nums[i])
                dp[i] = max(dp[i],1+dp[j]),ans = max(ans,dp[i]);
        return ans;
    }
};