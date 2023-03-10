// Problem Link - https://leetcode.com/problems/word-pattern/

#define ll int

class Solution {
public:
    bool wordPattern(string pattern, string s) {
     map<char, string> m1;
        map<string,char> m2;
        string str = "";
        ll ind = 0;
        ll ptInd = 0;
        s+=' ';
        while(ind<s.length())
        {
            if(s[ind]==' ')
            {
                cout<<str<<" "<<pattern[ptInd]<<endl;
                if(m1.count(pattern[ptInd])==0)
                {
                    m1[pattern[ptInd]] = str;
                }
                else
                {
                    if(m1[pattern[ptInd]]!=str)
                    {
                        return false;
                    }
                }
                
                if(m2.count(str)==0)
                {
                    m2[str] = pattern[ptInd];
                }
                else
                {
                    if(m2[str]!=pattern[ptInd])
                    {
                        return false;
                    }
                }
                ptInd++;
                str = "";
                while(s[ind]==' ')
                {
                    ind++;
                }
                continue;
            }
            str += s[ind];
            ind++;
        }
        if(ind!=s.length() or ptInd!=pattern.length())
            return false;
        return true;
    }
};
