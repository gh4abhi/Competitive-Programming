// Problem Link - https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

#define ll int

class Solution {
public:

    char findPar(char u, unordered_map<char,char> &par)
    {
        if(par[u]==u)
            return u;
        return par[u] = findPar(par[u],par);
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char,char> par;
        for(auto i:s1)
            par[i] = i;
        for(auto i:s2)
            par[i] = i;
        for(auto i:baseStr)
            par[i] = i;
        ll n = s1.length();
        for(ll i=0;i<n;i++)
        {
            char p1 = findPar(s1[i],par);
            char p2 = findPar(s2[i],par);
            if(p1<p2)
                par[p2] = p1;
            else 
                par[p1] = p2;
        }
        string ans = "";
        for(auto i:baseStr)
            ans += findPar(i,par);
        return ans;      
    }
};