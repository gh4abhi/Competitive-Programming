// Problem Link - https://leetcode.com/problems/find-all-duplicates-in-an-array/

#define ll int

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<ll> ans;
        for(ll i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            else
                nums[abs(nums[i])-1] *= (-1);
        }
        return ans;
    }
};