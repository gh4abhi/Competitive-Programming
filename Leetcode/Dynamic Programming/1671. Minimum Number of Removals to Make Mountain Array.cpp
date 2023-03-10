// Problem Link - https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

#define ll int

class Solution {
public:
    
    void lis(vector<ll>& nums, vector<ll> &dp)
    {
        ll n = nums.size();
        for(ll i=1;i<n;i++)
            for(ll j=i-1;j>=0;j--)
                if(nums[i]>nums[j] and dp[i]<1+dp[j])
                    dp[i] = 1+dp[j];
    }
    
    int minimumMountainRemovals(vector<int>& nums) {
        ll n = nums.size();
        vector<ll> dp1(n,1);
        vector<ll> dp2(n,1);
        lis(nums,dp1);
        reverse(nums.begin(),nums.end());
        lis(nums,dp2);
        reverse(dp2.begin(),dp2.end());
        ll ans = 1;
        for(ll i=0;i<nums.size();i++)
            if(dp1[i]>1 and dp2[i]>1)
                ans = max(ans,dp1[i]+dp2[i]-1);
        return n-ans;
    }
};