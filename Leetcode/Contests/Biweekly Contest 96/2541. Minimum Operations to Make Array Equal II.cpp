// Problem Link - https://leetcode.com/contest/biweekly-contest-96/problems/minimum-operations-to-make-array-equal-ii/

#define ll long long

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k==0)
        {
            if(nums1==nums2)
                return 0;
            return -1;
        }
        vector<ll> pos;
        vector<ll> neg;
        ll n = nums1.size();
        ll ok = 0;
        ll count = 0;
        for(ll i=0;i<n;i++)
        {
            ll op = nums1[i]-nums2[i];
            if(op%k!=0)
                return -1;
            count += abs(op/k);
            ok += op;
        }
        if(ok!=0)
            return -1;
        return count/2;
    }
};