// Problem Link - https://leetcode.com/problems/constrained-subsequence-sum/

#define ll int
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        ll n = nums.size();
        deque<ll> dq;
        vector<ll> dp(n);
        ll ans = nums[n-1];
        dp[n-1] = nums[n-1];
        dq.push_back(n-1);
        for(ll i=n-2;i>=0;i--)
        {
            if(dq.front()>i+k)
                dq.pop_front();
            ll maxi = 0;
            if(dq.size())
                maxi = dp[dq.front()];
            dp[i] = max(nums[i],nums[i]+maxi);
            ans = max(ans,dp[i]);
            while(dq.size() and dp[dq.back()]<dp[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return ans;
    }
};