// Problem Link - https://leetcode.com/problems/single-number/

#define ll int

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ll ans = 0;
        for(ll i=0;i<nums.size();i++)
            ans = ans^nums[i];
        return ans;
    }
};
