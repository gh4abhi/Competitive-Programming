// Problem Link - https://leetcode.com/contest/weekly-contest-282/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/

#define ll int

class Solution {
public:
    int minSteps(string s, string t) {
        map<char,ll> m1,m2;
        for(auto i:s)
            m1[i]++;
        for(auto i:t)
            m2[i]++;
        ll ans = 0;
        for(char ch='a';ch<='z';ch++)
        {
            ans += abs(m1[ch]-m2[ch]);
        }
        return ans;
    }
};