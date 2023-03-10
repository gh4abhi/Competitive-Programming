// Problem Link - https://leetcode.com/problems/count-and-say/

#define ll int

class Solution {
public:
    
    string countAndSayHelper(string str, ll n)
    {
        if(n==1)
            return str;
        map<char,ll> m;
        char check = str[0];
        string finalS = "";
        for(ll i=0; i<str.length();i++)
        {
            m[str[i]]++;
            if(str[i]!=check)
            {
                char temp = m[check] + '0';
                finalS = finalS + temp + check;
                m[check] = 0;
            }
            check = str[i];
        }
        char temp = m[check] + '0';
        // cout<<temp<<" "<<check<<endl;
                finalS = finalS + temp + check;
                m[check] = 0;
        return countAndSayHelper(finalS, n-1);
    }
    
    string countAndSay(int n) {
        return countAndSayHelper("1", n);
    }
};