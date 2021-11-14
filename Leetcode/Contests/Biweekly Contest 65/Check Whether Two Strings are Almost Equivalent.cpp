// Problem Link - https://leetcode.com/contest/biweekly-contest-65/problems/check-whether-two-strings-are-almost-equivalent/

#define ll int
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
     map<char,ll> m1,m2;
        for(auto i:word1)
        {
            m1[i]++;
            }
        for(auto i:word2)
        {
            m2[i]++;
        }
        
        for(auto i:word1)
        {
            if(abs(m1[i]-m2[i])>3)
            {
                return false;
            }
        }
        for(auto i:word2)
        {
            if(abs(m1[i]-m2[i])>3)
            {
                return false;
            }
        }
        return true;
    }
};
