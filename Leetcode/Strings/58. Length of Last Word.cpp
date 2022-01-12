// Problem Link - https://leetcode.com/problems/length-of-last-word/

#define ll int

class Solution {
public:
    int lengthOfLastWord(string str) {
        string s= "";
        for(ll i=str.length()-1;i>=0;i--)
        {
            if(str[i]!=' ')
            {
                s+=str[i];
            }
            else
            {
                if(s.length()!=0)
                    return s.length();
                s="";
            }
        }
        return s.length();
    }
};
