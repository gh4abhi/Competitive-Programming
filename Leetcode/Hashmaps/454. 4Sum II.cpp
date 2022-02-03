// Problem Link - https://leetcode.com/problems/4sum-ii/

#define ll int

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<ll,ll> m;
        for(auto i:nums1)
            for(auto j:nums2)
                m[i+j]++;
        ll ans = 0;
        for(auto i:nums3)
            for(auto j:nums4)
                ans+=m[-(i+j)];
        return ans;
    }
};
