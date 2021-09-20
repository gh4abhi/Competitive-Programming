// Problem Link - https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

#define ll long long
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        map<ll,ll> m;
        for(ll i=0;i<nums.size();i++)
        {
            for(ll j=0;j<nums.size();j++)
            {
                ll diff = abs(nums[i]-nums[j]);
                m[diff]++;
            }
        }
        return m[k]/2;
    }
};
