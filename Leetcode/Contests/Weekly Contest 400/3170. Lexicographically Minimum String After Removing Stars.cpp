// Problem Link - https://leetcode.com/contest/weekly-contest-400/problems/lexicographically-minimum-string-after-removing-stars/

#define ll int

class Solution {
public:
    string clearStars(string s) {
        ll n = s.length();
        vector<ll> vis(n,0);
        map<char,vector<ll>> m;
        for(ll i=0;i<s.length();i++)
        {
            if(s[i]=='*')
            {
                auto it = m.begin();
                (it->second).pop_back();
                if((it->second).size()==0)
                    m.erase(it->first);
            }
            else
                m[s[i]].push_back(i);
        }
        for(auto i:m)
            for(auto j:i.second)
                vis[j] = 1;
        string ans = "";
        for(ll i=0;i<n;i++)
            if(vis[i])
                ans+=s[i];
        return ans;
    }
};