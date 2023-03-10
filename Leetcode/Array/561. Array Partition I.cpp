// Problem Link - https://leetcode.com/problems/array-partition-i/

#define ll int

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        ll ans = 0;
        sort(nums.begin(),nums.end());
        for(ll i=0;i<nums.size();i+=2)
            ans+=nums[i];
        return ans;
    }
};