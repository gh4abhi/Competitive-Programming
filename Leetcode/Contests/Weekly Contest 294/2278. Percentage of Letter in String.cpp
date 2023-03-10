// Problem Link - https://leetcode.com/contest/weekly-contest-294/problems/percentage-of-letter-in-string/

#define ll long long

class Solution {
public:
    int percentageLetter(string s, char letter) {
        map<char,ll> m;
        for(auto i:s)
            m[i]++;
        ll val = ((m[letter]*100)/s.length());
        return (int)val;
    }
};