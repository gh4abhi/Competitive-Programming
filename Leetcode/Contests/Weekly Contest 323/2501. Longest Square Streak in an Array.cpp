// Problem Link - https://leetcode.com/contest/weekly-contest-323/problems/longest-square-streak-in-an-array/

#define ll long long

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<ll,ll> m;
        for(auto i:nums)
            m[i]++;
        ll ans = 0;
        for(auto i:m)
        {
            ll op = i.first;
            ll ok = 1;
            while(m.count(op*op))
                op = op*op, ok+=1;
            ans = max(ans,ok);
        }
        if(ans==1)
            return -1;
        return ans;
    }
};