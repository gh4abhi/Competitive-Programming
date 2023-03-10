// Problem link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#define ll int

class Solution {
public:
    
    vector<string> ans;
    
    void letterCombinationsHelper(map<ll,string> m, string digits, string str, ll ind)
    {
        if(str.length()==digits.length())
        {
            ans.push_back(str);
            return;
        }
        
        for(ll i=ind;i<ind+1;i++)
        {
            for(ll j=0;j<m[digits[i]-'0'].length();j++)
            { 
                letterCombinationsHelper(m, digits, str + m[digits[i]-'0'][j], ind+1);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
        {
            return ans;
        }
        map<ll,string> m;
        char ch = 'a';
        for(ll i=2;i<=9;i++)
        {
            for(ll j=0;j<3;j++)
            {
                m[i]+=ch;
                ch++;
                if((i==7 and j==2) or (i==9 and j==2))
                {
                    m[i] += ch;
                    ch++;
                }
            }
        }
        letterCombinationsHelper(m, digits, "", 0);
        return ans;
    }
};
