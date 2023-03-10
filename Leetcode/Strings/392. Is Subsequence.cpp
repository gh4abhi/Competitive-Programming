// Problem Link - https://leetcode.com/problems/is-subsequence/

#define ll int

class Solution {
public:
    bool isSubsequence(string s, string t) {
        ll sub = 0;
        for(ll i=0;i<t.length();i++)
        {
            if(s[sub]==t[i] and sub<s.length())
                sub++;
        }
        return sub==(s.length());
    }
};