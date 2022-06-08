// Problem Link - https://leetcode.com/problems/remove-palindromic-subsequences/

#define ll int

class Solution {
public:
    int removePalindromeSub(string s) {
        map<char,ll> m;
        string str = s;
        reverse(str.begin(),str.end());
        if(str==s)
            return 1;
        for(auto i:s)
            m[i]++;
        return m.size();
    }
};