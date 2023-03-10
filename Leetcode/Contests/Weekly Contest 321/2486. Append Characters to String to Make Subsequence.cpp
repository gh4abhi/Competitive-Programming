// Problem Link - https://leetcode.com/contest/weekly-contest-321/problems/append-characters-to-string-to-make-subsequence/

#define ll int

class Solution {
public:
    int appendCharacters(string s, string t) {
        ll k = 0;
        for(ll i=0;i<s.length();i++)
            if(k<t.length() and s[i]==t[k])
                k++;
        return (t.length()-k);
    }
};