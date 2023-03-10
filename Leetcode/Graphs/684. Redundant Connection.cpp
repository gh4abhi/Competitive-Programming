// Problem Link - https://leetcode.com/problems/redundant-connection/

#define ll int

class Solution {
public:
    
    ll findPar(ll u, vector<ll>& par )
    {
        if(par[u]==u)
           return u;
        return par[u] = findPar(par[u],par);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       ll n = edges.size();
       vector<ll> par(n+1);
        vector<ll> ans;
       for(ll i=1;i<=n;i++)
       {
           par[i]=i;
       }
        for(auto i:edges)
        {
            ll v1 = i[0];
            ll v2 = i[1];
            ll p1 = findPar(v1,par);
            ll p2 = findPar(v2,par);
            if(p1!=p2)
            {
                par[p1]=par[p2];
            }
            else
            {
                ans = i;
            }
        }
        return ans;
    }
};
