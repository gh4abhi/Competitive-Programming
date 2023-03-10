// Problem Link - https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

#define ll int

class Solution {
public:

    void DFS(ll ind, ll & ans, unordered_map<string,ll> &m, string &s)
    {
        if(ind==s.length())
        {
            ans = max(ans,(ll)m.size());
            return;
        }
        for(ll i=ind; i<s.length(); i++)
        {
            string op = s.substr(ind,i-ind+1);
            if(m.count(op)==0)
            {
                m[op]++;
                DFS(i+1,ans,m,s);
                m.erase(op);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        ll ans = 0;
        unordered_map<string,ll> m;
        DFS(0,ans,m,s);
        return ans;
    }
};