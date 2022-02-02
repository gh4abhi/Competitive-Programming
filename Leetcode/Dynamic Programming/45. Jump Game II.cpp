// Problem Link - https://leetcode.com/problems/jump-game-ii/

#define ll int
class Solution {
public:
    int jump(vector<int>& nums) {
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
                if(dp[i+j]==0)
                   continue; 
                mini = min(dp[i+j],mini);
            }
            
            if(mini==INT_MAX)
                continue;
            dp[i] = 1 + mini;
        }
        return dp[0]-1;
    }
};
