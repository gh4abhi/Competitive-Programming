// Problem Link - https://leetcode.com/problems/product-of-array-except-self/

#define ll int

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ll pro = 1;
        ll ok = 0;
        ll op = 1;
        ll count = 0;
        for(auto i:nums)
        {
            if(i!=0)
                op*=i;
            else
                count++;
            pro*=i;
        }
        vector<ll> ans(nums.size());
        if(count>1)
            return ans;        
        for(ll i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                ans[i] = op;
            else
                ans[i] = pro/nums[i];
        }
        return ans;
    }
};