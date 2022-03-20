// Problem Link - https://leetcode.com/contest/biweekly-contest-74/problems/divide-array-into-equal-pairs/

#define  ll int

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<ll,ll> m;
        for(auto i:nums)
            m[i]++;
        for(auto i:m)
        {
            if(i.second&1)
                return false;
        }
        return true;
    }
};