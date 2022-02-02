// Problem Link - https://leetcode.com/problems/jump-game/

#define ll int

class Solution {
public:
    bool canJump(vector<int>& nums) {
        ll n = nums.size();
        vector<ll> dp(n,0);
        dp[n-1] = 1;
        for(ll i=n-2;i>=0;i--)
        {
            ll mini = INT_MAX;
            for(ll j=1;j<=nums[i];j++)
            {
                if(i+j>n-1)
                    break;
                if(dp[i+j]!=0)
                {
                   dp[i] = 1; 
                   break; 
                }
            }
        }
        if(dp[0])
            return true;
        return false;
    }
};
