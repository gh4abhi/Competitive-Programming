// Problem Link - https://leetcode.com/problems/smallest-string-with-swaps/

#define ll int

class Solution {
public:
    
    ll findPar(ll u, vector<ll>& par)
    {
        if(par[u]==u)
            return u;
        return par[u] = findPar(par[u],par);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        ll n = s.length();
        vector<ll> par(s.length(),0);
        for(ll i=0;i<par.size();i++)
            par[i] = i;
        for(auto i:pairs)
        {
            ll a = i[0];              
            ll b = i[1];
            ll pa = findPar(a,par);
            ll pb = findPar(b,par);
            par[pb] = pa;
        }
        map<ll,vector<ll>> m;
        for(ll i=0;i<n;i++)
            m[findPar(i,par)].push_back(i);
        string ans = string(n,' ');
        for(auto i:m)
        {
            string temp = "";
            for(auto j:i.second)
                temp += s[j];
            sort(temp.begin(),temp.end());
            ll k = 0;
            for(auto j:i.second)
                ans[j] = temp[k++];
        }
        return ans;
    }
};