// Problem Link - https://leetcode.com/problems/reach-end-of-array-with-max-score/description/

#define ll long long

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        ll n = nums.size();
        nums[n-1] = 1e6;
        ll maxi = nums[0];
        ll ind = 0;
        ll ans = 0;
        for(ll i=1;i<n;i++)
            if(nums[i]>nums[ind])
                ans += (i-ind)*nums[ind], ind = i;
        return ans;
    }
};