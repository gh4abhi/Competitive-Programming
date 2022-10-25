// Problem Link - https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

#define ll int

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        ll i = 0, j = 0;
        ll x = 0, y = 0;
        while(i<word1.size() and j<word2.size())
        {
            if(word1[i][x]!=word2[j][y])
                return false;
            else
                x++,y++;
            if(x==word1[i].length())
                x=0,i++;
            if(y==word2[j].length())
                y=0,j++;
        }
        return i==word1.size() and j==word2.size();
    }
};