// Problem Link - https://leetcode.com/problems/subsets/

#define ll int

class Solution {
public:
    vector<vector<ll>> ans;
    
    void subsetsHelper(vector<int>& nums, ll ind, vector<ll> sub)
    {
        if(ind>=nums.size())
        {
            ans.push_back(sub);
            return;
        }
        subsetsHelper(nums,ind+1,sub);
        sub.push_back(nums[ind]);
        subsetsHelper(nums,ind+1,sub);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<ll> sub;
        subsetsHelper(nums,0,sub);
        return ans;
    }
};
