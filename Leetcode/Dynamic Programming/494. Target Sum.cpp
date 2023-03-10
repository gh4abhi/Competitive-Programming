// Problem Link - https://leetcode.com/problems/target-sum/

#define ll int

class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {
        ll ts = 0;
        if(nums.size()==1)
            return abs(nums[0]) == abs(target);
        for(auto i:nums)
            ts+=i;
        vector<vector<ll>> dp(nums.size()+1,vector<ll>(ts+1,0));
        if((ts + target)%2 != 0) return 0;
        ll op = (ts+target)/2;
        dp[0][0] = 1;
        for(ll i=1;i<nums.size()+1;i++)
        {
            for(ll j=0;j<ts+1;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j>=nums[i-1])
                    dp[i][j]+=dp[i-1][j-nums[i-1]];
            }
        }
        if(target>ts)
            return 0;
        return dp[nums.size()][op];
    }
};