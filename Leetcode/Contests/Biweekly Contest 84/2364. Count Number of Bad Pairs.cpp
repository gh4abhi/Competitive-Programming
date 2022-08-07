// Problem Link - https://leetcode.com/contest/biweekly-contest-84/problems/count-number-of-bad-pairs/

#define ll long long

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<ll,ll> m;
        for(ll i=0;i<nums.size();i++)
        {
            m[nums[i]-i]++;
        }
        ll ans = 0;
        for (auto i : m) {
        ll cnt = i.second; 
        ans += ((cnt * (cnt - 1)) / 2);
    }
        ll val = ((nums.size())*(nums.size()-1))/2;
        return val - ans;
    }
};