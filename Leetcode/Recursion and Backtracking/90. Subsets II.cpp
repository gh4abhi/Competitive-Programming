// Problem Link - https://leetcode.com/problems/subsets-ii/submissions/

#define ll int

class Solution {
public:
    
    vector<vector<int>> ans;
    void subsetsWithDupHelper(vector<int>& nums, vector<ll> temp, ll i)
    {
        ans.push_back(temp);
        ll lastPicked = -11;
        for(ll j = i;j<nums.size();j++)
        {
            if(j!=i and nums[j]==lastPicked)
                continue;
            lastPicked = nums[j];
            temp.push_back(nums[j]);
            subsetsWithDupHelper(nums,temp,j+1);
            temp.pop_back();
        }
    }    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<ll> t;
        subsetsWithDupHelper(nums, t, 0);
        return ans;
    }
};