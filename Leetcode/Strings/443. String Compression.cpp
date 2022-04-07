// Problem Link - https://leetcode.com/problems/string-compression/

#define ll int

class Solution {
public:
    int compress(vector<char>& chars) {
        string str = "";
        map<char,ll> m;
        char check = chars[0];
        for(ll i=0;i<chars.size();i++)
        {
            m[chars[i]]++;
            if(check != chars[i])
            {
                if(m[check]==1)
                    str = str + check;
                else
                {
                    string temp = to_string(m[check]);
                    str = str + check + temp;
                }
                m[check] = 0;
            }
            check = chars[i];
        }
        if(m[check]==1)
            str = str + check;
        else
             {
            string temp = to_string(m[check]);
                    str = str + check + temp;
                }
        for(ll i=0;i<str.length();i++)
            chars[i] = str[i];
        return str.length();
    }
};