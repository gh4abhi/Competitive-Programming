// Problem Link - https://leetcode.com/contest/weekly-contest-315/problems/count-number-of-distinct-integers-after-reverse-operations/

#define ll long long

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        map<ll,ll> m;
        for(auto i:nums)
            m[i]++;
        for(auto i:nums)
        {
            ll op = i;
            ll ok = 0;
            while(op)
            {
                ok = ok*10 + op%10;
                op/=10;
            }
            m[ok]++;
        }
        return m.size();
    }
};