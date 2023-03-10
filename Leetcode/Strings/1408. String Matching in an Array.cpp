// Problem Link - https://leetcode.com/problems/string-matching-in-an-array/

#define ll int

class Solution {
public:
    
    vector<ll> prefixFunction(string &p)
    {
        ll n = p.length();
        vector<ll> prefix(n,0);
        prefix[0]  = 0;
        for(ll i=1;i<n;i++)
        {
            ll j = prefix[i-1];
            while(j>0 and p[i]!=p[j])
                j++;
            if(p[i]==p[j])
                j++;
            prefix[i] = j;
        }
        return prefix;
    }
    
    bool kmp(string &s, string &p, vector<ll> &prefix)
    {
        ll m = s.length();
        ll n = p.length();
        ll i = 0, j = 0;
        while(i<m)
        {
            if(s[i]==p[j])
                i+=1,j+=1;
            else
            {
                if(j>0)
                    j = prefix[j-1];
                else
                    i+=1;
            }
            if(j==n)
                return true;
        }
        return false;
    }
    
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(ll i=0;i<words.size();i++)
        {
            vector<ll> prefix = prefixFunction(words[i]);
            for(ll j=0;j<words.size();j++)
            {
                if(i==j)
                    continue;
                if(words[j].find(words[i]) != -1){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};