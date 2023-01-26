// Problem Link - https://practice.geeksforgeeks.org/problems/95080eb9efbf7cc5cb4851ddf8d7946e3f212a49/1

#define ll int

class Solution {
  public:
    
    vector<ll> prefixFunction(string &s)
    {
        ll n = s.length();
        vector<ll> prefix(n,0);
        prefix[0] = 0;
        for(ll i=1;i<n;i++)
        {
            ll j = prefix[i-1];
            while(j>0 and s[i]!=s[j])
                j = prefix[j-1];
            if(s[i]==s[j])
                j++;
            prefix[i] = j;
        }
        return prefix;
    }
    
    int minOperation(string s) {
        vector<ll> prefix = prefixFunction(s);
        ll ans = 0;
        ll n = s.length();
        ll ok = 1;
        for(ll i=n-1;i>=0;i--)
        {
            if(prefix[i]==i-prefix[i]+1 and ok)
                i = prefix[i], ok = 0, ans += 1;
            else if(prefix[i]==i and ok)
                ans += max(prefix[i],1), ok = 0, i=0;
            else
                ans += 1;
        }
        return ans;
    }
};