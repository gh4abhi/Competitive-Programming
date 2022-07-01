// Problem Link - https://leetcode.com/problems/jump-game-vi/

#define ll int

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<ll> dq;
        ll n = nums.size();
        vector<ll> dp(nums.size());
        dp[n-1] = nums[n-1];
        dq.push_back(n-1);
        for(ll i=n-2;i>=0;i--)
        {
            if(dq.front()>i+k)
                dq.pop_front();
            dp[i] = nums[i] + dp[dq.front()];
            while(dq.size() and dp[dq.back()]<dp[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return dp[0];
    }
};