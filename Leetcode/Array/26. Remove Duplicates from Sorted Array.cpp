// Problem Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#define ll int

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        ll n = nums.size();
        if(n<2)
            return n;
        ll ind = 1;
        for(ll i=1;i<n;i++)
        {
            if(nums[i]!=nums[ind-1])
            {
                nums[ind++] = nums[i];
            }
        }
        return ind;
    }
};
