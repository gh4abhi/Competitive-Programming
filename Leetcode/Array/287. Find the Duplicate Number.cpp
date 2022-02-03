// Problem Link - https://leetcode.com/problems/find-the-duplicate-number/

// Approach 1 

#define ll int

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(ll i=0;i<nums.size();i++)
        {
            ll ind = abs(nums[i]);
            if(nums[ind]<0)
                return ind;
            nums[ind]*=-1;
        }
        return -1;
    }
};
