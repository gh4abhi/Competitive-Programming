// Problem Link - https://leetcode.com/contest/weekly-contest-318/problems/apply-operations-to-an-array/

#define ll int

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        ll n = nums.size();
        for(ll i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
                nums[i]*=2, nums[i+1] = 0;
        }
        vector<ll> ans(n,0);
        ll k = 0;
        for(auto i:nums)
            if(i!=0)
                ans[k++] = i;
        return ans;
    }
};