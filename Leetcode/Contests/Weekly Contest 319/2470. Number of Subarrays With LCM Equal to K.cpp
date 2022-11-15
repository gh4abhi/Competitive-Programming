// Problem Link - https://leetcode.com/contest/weekly-contest-319/problems/number-of-subarrays-with-lcm-equal-to-k/

#define ll long long

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        ll ans = 0;
        for(ll i=0;i<nums.size();i++)
        {
            ll op = nums[i];
            for(ll j=i;j<nums.size();j++)
            {
                op = lcm(op,nums[j]);
                if(op>k)
                    break;
                if(op==k)
                    ans++;
            }
        }
        return ans;
    }
};