// Problem Link - https://leetcode.com/problems/arithmetic-slices/

#define ll int

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        ll i = 0, j = 1, k = 2;
        ll count = 0;
        ll val = 0;
        ll len = 0;
        while(k<nums.size())
        {
            if(nums[j]-nums[i]==nums[k]-nums[j])
            {
                val = val + 1 + len;
                len++;
            }
            else
            {
                count+=val;
                val = 0;
                len = 0;
            }
            i++;
            j++;
            k++;
        }
        if(val!=0)
            count+=val;
        return count;
    }
};