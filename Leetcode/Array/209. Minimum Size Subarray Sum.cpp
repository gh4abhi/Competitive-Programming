// Problem Link - https://leetcode.com/problems/minimum-size-subarray-sum/
// Solved using two pointers.

#define ll int

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        ll i=0,j=0;
        ll mini =INT_MAX;
        ll n = nums.size();
        ll sum = 0;
        while(1)
        {
            if(sum<target and j==n)
                break;
            
            if(sum<target)
            {
                sum += nums[j];
                j++;
            }
            else
            {
                mini = min(mini, j-i);
                sum-=nums[i];
                i++;
            }
        }
        if(mini==INT_MAX)
            return 0;
        return mini;
    }
};
