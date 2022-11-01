// Problem Link - https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

#define ll int

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string str = "";
        for(ll i=0;i<s.length();i++)
        {
            if(str.length()<part.length()-1)
                str += s[i];
            else
            {
                str += s[i];
                ll n = str.length();
                if(str.back()==part.back())
                    if(str.substr(n-part.length(),part.length())==part)
                        str = str.substr(0,n-part.length());
            }
        }
        return str;
    }
};