// Problem Link - https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/

#define ll int

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        ll flag = 0;
        for(ll i=1;i<nums.size();i++)
        {
            if(nums[i]<=nums[i-1])
            {
                if(flag)
                    return false;
                if(i>1 and nums[i]<=nums[i-2])
                    nums[i] = nums[i-1];
                flag++;
            }
        }
        return true;
    }
};
