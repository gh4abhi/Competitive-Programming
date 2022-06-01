// Problem Link - https://leetcode.com/contest/biweekly-contest-79/problems/check-if-number-has-equal-digit-count-and-digit-value/

#define ll long long

class Solution {
public:
    bool digitCount(string num) {
        map<ll,ll> m;
        for(auto i:num)
        {
            ll val = (i-'0');
            m[val]++;
        }
        string str = "";
        for(ll i=0;i<num.size();i++)
        {
            str+=to_string(m[i]);
        }
        return str==num;
    }
};