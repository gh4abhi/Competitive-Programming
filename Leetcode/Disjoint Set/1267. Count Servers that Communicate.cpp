// Problem Link - https://leetcode.com/problems/count-servers-that-communicate/

#define ll int  

class Solution {
public:
    
    ll findPar(ll u, vector<ll> &par)
    {
        if(par[u]==u)
            return u;
        return par[u] = findPar(par[u],par);
    }
    
    void setUnion(ll a, ll b, vector<ll>& par, vector<ll> &rank)
    {
        ll p1 = findPar(a,par);
        ll p2 = findPar(b,par);
        if(p1!=p2)
        {
            if(rank[p1]>rank[p2])
                par[p2] = p1;
            else if(rank[p2]>rank[p1])
                par[p1] = p2;
            else
                par[max(p1,p2)] = min(p1,p2), rank[min(p1,p2)]++;
        }
    }
    
    int countServers(vector<vector<int>>& grid) {
        ll m = grid.size();
        ll n = grid[0].size();
        vector<vector<ll>> nodes;
        for(ll i=0;i<m;i++)
            for(ll j=0;j<n;j++)
                if(grid[i][j]==1)
                    nodes.push_back({i,j});
        vector<ll> par(nodes.size());
        vector<ll> rank(nodes.size(),0);
        for(ll i=0;i<nodes.size();i++)
            par[i] = i;
        for(ll i=0;i<nodes.size();i++)
            for(ll j=i+1;j<nodes.size();j++)
                if(nodes[i][0]==nodes[j][0] or nodes[i][1]==nodes[j][1])
                    setUnion(i,j,par,rank);
        ll ans = 0;
        for(ll i=0;i<nodes.size();i++)
            if(par[i]!=i or rank[i]>0)
                ans++;
        return ans;
    }
};