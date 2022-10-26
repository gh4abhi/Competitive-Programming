// Problem Link - https://leetcode.com/problems/continuous-subarray-sum/

#define ll int

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<ll,ll> m;
        m[0] = 0;
        ll sum = 0;
        for(ll i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(m.count(sum%k)==0)
                m[sum%k] = i+1;
            else if(m[sum%k]<i)
                return true;
        }
        return false;
    }
};