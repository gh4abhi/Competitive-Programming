// Problem Link - https://leetcode.com/problems/find-subarrays-with-equal-sum/

#define ll int

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        map<ll,ll> m;
        if(nums.size())
        for(ll i=0;i<nums.size()-1;i++)
        {
            ll sum = 0;
            for(ll j=i;j<i+2;j++)
            {
                sum += nums[j];
            }
            m[sum]++;
            if(m[sum]>1)
                return true;
        }
        return false;
    }
};