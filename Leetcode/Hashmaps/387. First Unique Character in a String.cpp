// Problem Link - https://leetcode.com/problems/first-unique-character-in-a-string/ 

#define ll int

class Solution {
public:
    int firstUniqChar(string s) {
        map<char,ll> m;
        for(auto i:s)
            m[i]++;
        for(ll i=0;i<s.length();i++)
            if(m[s[i]]==1)
                return i;
        return -1;
    }
};