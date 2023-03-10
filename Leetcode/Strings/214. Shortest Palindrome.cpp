// Problem Link - https://leetcode.com/problems/shortest-palindrome/

#define ll int

class Solution {
public:
    vector<ll> prefixFunction(string p)
    {
        ll n = p.length();
        vector<ll> prefix(n,0);
        prefix[0] = 0;
        for(ll i=1;i<n;i++)
        {
            ll j = prefix[i-1];
            while(j>0 and p[i]!=p[j])
                j = prefix[j-1];
            if(p[i]==p[j])
                j++;
            prefix[i] = j;
        }
        return prefix;
    }
    string shortestPalindrome(string s) {
        string str = s;
        string op = str;
        reverse(op.begin(),op.end());
        str += "$" + op;
        ll n = s.length();
        vector<ll> prefix = prefixFunction(str);
        ll val = prefix[2*n];
        string ok = s.substr(val,n);
        reverse(ok.begin(),ok.end());
        string ans = ok+s;
        return ans;
    }
};