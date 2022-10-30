// Problem Link - https://leetcode.com/contest/biweekly-contest-90/problems/odd-string-difference/

#define ll int

class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<ll>,ll> m;
        map<string,vector<ll>> op;
        ll n = words.size();
        for(ll i=0;i<n;i++)
        {
            vector<ll> ok;
            for(ll j=0;j<words[i].size()-1;j++)
            {
                ok.push_back(words[i][j+1]-words[i][j]);
            }
            m[ok]++;
            op[words[i]] = ok;
        }
        for(auto i:words)
            if(m[op[i]]==1)
                return i;
        return "a";
    }
};