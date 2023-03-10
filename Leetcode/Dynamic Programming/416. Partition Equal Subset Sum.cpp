// Problem Link - https://leetcode.com/problems/partition-equal-subset-sum/

#define ll int
#define MOD 1000000007

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        ll sum = accumulate(nums.begin(), nums.end(),0);
        if(sum&1)
            return false;
        sum = sum/2;
        vector<vector<bool>> dp(nums.size()+1,vector<bool>(sum+1,false));
        dp[0][0] = true;
        for(ll i=1;i<nums.size()+1;i++)
        {
            for(ll j=1;j<sum+1;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j>=nums[i-1])
                    dp[i][j] = dp[i][j] or dp[i-1][j-nums[i-1]];
                if(j==sum and dp[i][j])
                    return true;
            }
        }
        return false;
    }
};
