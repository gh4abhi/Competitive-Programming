// Problem Link - https://leetcode.com/contest/weekly-contest-315/problems/largest-positive-integer-that-exists-with-its-negative/

#define ll int

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<ll,ll> m;
        for(auto i:nums)
            m[i]++;
        ll ans = -1;
        for(auto i:nums)
        {
            if(i>0 and m.count(-i))
                ans = max(ans,i);
        }
        return ans;
    }
};