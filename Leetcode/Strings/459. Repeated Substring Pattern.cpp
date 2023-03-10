// Problem Link - https://leetcode.com/problems/repeated-substring-pattern/

#define ll int

class Solution {
public:
    bool prefixFunction(string p)
    {
    ll n = p.length();
    vector<ll> prefix(n,0);
    for(ll i=1;i<n;i++)
    {
        ll j = prefix[i-1];
        while(j>0 and p[i]!=p[j])
            j = prefix[j-1];
        if(p[i]==p[j])
            j++;
        prefix[i] = j;
    }
    if(prefix[n-1]==0)
        return false;
    return prefix[n-1]%(n-prefix[n-1])==0;
    }
    bool repeatedSubstringPattern(string s) {
    return prefixFunction(s);
    }
};