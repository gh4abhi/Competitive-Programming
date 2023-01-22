// Problem Link - https://leetcode.com/contest/biweekly-contest-96/problems/minimum-common-value/

#define ll int

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<ll,ll> m;
        for(auto i:nums1)
            m[i]++;
        for(auto i:nums2)
            if(m.count(i))
                return i;
        return -1;
    }
};