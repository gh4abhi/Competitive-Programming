// Problem Link - https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#define ll int

class Solution {
public:
    vector<ll> par;    
    ll findPar(ll u)
    {
        if(par[u]!=u)
        {
            return findPar(par[u]);
        }
        return u;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        for(ll i=0;i<n;i++)
        {
            par.push_back(i);
        }
        
        for(auto i:connections)
        {
            ll u = i[0];
            ll v = i[1];
            
            ll p1 = findPar(u);
            ll p2 = findPar(v);
            
            if(p1!=p2)
            {
                par[p2] = p1;
            }
        }
        
        ll components = 0;
        
        for(ll i=0;i<n;i++)
        {
            ll p = findPar(i);
            if(p==i)
                components++;
        }
       return components-1;
    }
};
