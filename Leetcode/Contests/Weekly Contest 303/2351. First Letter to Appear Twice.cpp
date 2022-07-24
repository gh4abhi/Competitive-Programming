// Problem Link - https://leetcode.com/contest/weekly-contest-303/problems/first-letter-to-appear-twice/

#define ll int
class Solution {
public:
    char repeatedCharacter(string s) {
        map<char,ll> m;
        for(auto i:s)
        {
            m[i]++;
            if(m[i]==2)
                return i;
        }
        return 'a';
    }
};