// Problem Link - https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#define ll int

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        ll start = 0, end = nums.size()-1;
        while(start<=end)
        {
            ll mid = start + (end-start)/2;
            if(nums[mid]==target)
                return true;
            if(nums[start]<nums[mid])
            {
                if(target>=nums[start] and target<=nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else if(nums[start]>nums[mid])
            {
                if(target>=nums[mid] and target<=nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else
                start++;
        }
        return false;
    }
};