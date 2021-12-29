// Problem Link - https://leetcode.com/problems/missing-number/

#define ll int

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ll a = 0, b = nums[0];
        for(ll i=1;i<=(nums.size());i++)
        {
            a = a^i;
        }
        
        for(ll i=1;i<nums.size();i++)
        {
            b = b^nums[i];
        }
        
        return (a^b);
    }
};
