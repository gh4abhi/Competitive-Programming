// Problem Link - https://leetcode.com/problems/global-and-local-inversions/

#define ll long long

class Solution {
public:
    
    bool isIdealPermutation(vector<int>& nums) {
        for(ll i=0;i<nums.size();i++)
        {
            if(abs(nums[i]-i)>1)
                return false;
        }
        return true;
    }
};