// Problem Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

#define ll int

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        ll n = nums.size();
        if(n<3)
            return n;
        ll ind = 2;
        for(ll i=2;i<n;i++)
        {
            if(nums[i]!=nums[ind-2])
            {
                nums[ind++] = nums[i];
            }
        }
        return ind;
    }
};
