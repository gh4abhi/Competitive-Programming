// Problem Link - https://leetcode.com/contest/weekly-contest-295/problems/rearrange-characters-to-make-target-string/

#define ll long long

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char,ll> m1,m2;
        for(auto i:s)
            m1[i]++;
        for(auto i:target)
            m2[i]++;
        ll ans = s.length();
        for(auto i:m2)
            ans = min(ans,m1[i.first]/i.second);
        return (int)ans;
    }
};