// Problem Link - https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/

#define ll int

class Solution {
public:
    bool isValid(string s) {
        vector<char> vect;
        for(ll i=0;i<s.length();i++)
        {
            if(vect.size()<2)
                vect.push_back(s[i]);
            else
            {
                ll n = vect.size();
                if(s[i]=='c' and vect[n-1]=='b' and vect[n-2]=='a')
                    vect.pop_back(),vect.pop_back();
                else
                    vect.push_back(s[i]);
            }
        }
        return vect.size()==0;
    }
};