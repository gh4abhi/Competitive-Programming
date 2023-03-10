// Problem Link - https://leetcode.com/contest/weekly-contest-329/problems/apply-bitwise-operations-to-make-strings-equal/

#define ll int

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if(s==target)
            return true;
        map<char,ll> m1;
        for(auto i:s)
            m1[i]++;
        ll ok = 1;
        ll n = s.length();
        map<char,ll> m2;
        for(auto i:target)
            m2[i]++;
        if(m1.count('1') and m2.count('1')==0)
            return false;
        else if(m1.count('1')==0 and m2.count('1'))
            return false;
        return true;
    }
};