// Problem Link - https://leetcode.com/problems/camelcase-matching/

#define ll int

class Solution {
public:

    bool kmp(string &s, string &p)
    {
        ll m = s.length();
        ll n = p.length();
        ll i=0,j=0;
        while(i<m)
        {
            if(s[i]>='A' and s[i]<='Z' and (j==n or (p[j]>='A' and p[j]<='Z' and s[i]!=p[j]))) 
                return false;
            if(s[i]==p[j])
                i++,j++;
            else
                i++;
        }
        return j==n;
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(auto i:queries)
            ans.push_back(kmp(i,pattern));
        return ans;
    }
};