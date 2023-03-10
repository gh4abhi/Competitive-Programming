// Problem Link - https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

#define ll long long

class Solution {
public:
    int minSteps(string s, string t) {
        ll ans = 0;
        map<char,ll> m1,m2;
        for(auto i:s)
            m1[i]++;
        for(auto j:t)
            m2[j]++;
        for(auto i:m1)
            ans += max(0ll,i.second-m2[i.first]);
        return (int)ans;
    }
};