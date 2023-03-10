// Problem Link - https://leetcode.com/problems/largest-perimeter-triangle/

#define ll int

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(ll i=nums.size()-1;i>=2;i--)
            if(nums[i]<nums[i-1]+nums[i-2])
                return nums[i] + nums[i-1] + nums[i-2];
        return 0;
    }
};