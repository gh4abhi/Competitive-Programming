// Problem Link - https://leetcode.com/problems/repeated-string-match/

#define ll long long

class Solution {
public:
    
    bool rabinKarp(string &str, string &p)
    {
        ll d = 26;
        ll r = 5381;
        ll hashPat = 0;
        ll hashStr = 0;
        ll n = str.length();
        ll m = p.length();
        for(ll i=0;i<m;i++)
            hashPat = (hashPat*d + (p[i]-'a'+1))%r;
        ll start = 0, end = 0;
        ll op = 1;
        for(ll i=0;i<m-1;i++)
            op = (op*d)%r;
        while(end<n)
        {
            if(hashStr<0)
                hashStr += r;
            hashStr = (hashStr*d + (str[end] -'a' + 1))%r;
            if(end-start+1==m)
            {
                if(hashStr==hashPat and str.substr(start,m)==p)
                    return 1;
                hashStr = (hashStr - (str[start]-'a' + 1)*op)%r;
                start++;
            }
            end++;
        }
        return 0;
    }
    
    int repeatedStringMatch(string a, string b) {
        if(a==b)
            return 1;
        ll ans = 0;
        string str = "";
        while(str.length()<b.length())
        {
            str += a;
            ans++;
        }
        if(rabinKarp(str,b))
            return ans;
        str += a;
        if(rabinKarp(str,b))
            return ans+1;
        return -1;
    }
};