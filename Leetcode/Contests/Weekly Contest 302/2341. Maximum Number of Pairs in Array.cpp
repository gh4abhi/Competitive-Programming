// Problem Link - https://leetcode.com/contest/weekly-contest-302/problems/maximum-number-of-pairs-in-array/

#define ll int

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<ll,ll> m;
        for(auto i:nums)
            m[i]++;
        ll c1 = 0, c2 = 0;
        for(auto i:m)
        {
            c1 += i.second/2;
            if(i.second&1)
                c2 += 1;
        }
        vector<ll> ans;
        ans.push_back(c1);
        ans.push_back(c2);
        return ans;
    }
};