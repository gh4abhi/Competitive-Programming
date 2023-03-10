// Problem Link - https://leetcode.com/problems/isomorphic-strings/

#define ll int

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m1;
        map<char,char> m2;
        if(s.length()!=t.length())
        {
            return false;
        }
        ll ind = 0;
        while(ind!=s.length())
        {
            if(m1.count(s[ind])==0)
            {
                m1[s[ind]] = t[ind];
            }
            else
            {
                if(m1[s[ind]]!=t[ind])
                    return false;
            }
            if(m2.count(t[ind])==0)
            {
                m2[t[ind]] = s[ind]; 
            }
            else
            {
                if(m2[t[ind]]!=s[ind])
                    return false;
            }
            ind++;
        }
        return true;
    }
};
