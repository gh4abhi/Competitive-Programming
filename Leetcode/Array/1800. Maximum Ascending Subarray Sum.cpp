// Problem Link - https://leetcode.com/problems/maximum-ascending-subarray-sum/

#define ll int
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        ll sum = nums[0];
        ll ans = nums[0];
        for(ll i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                sum += nums[i];
            else
                sum = nums[i];
            ans = max(ans,sum);
        }
        return ans;
    }
};