// Problem Link - https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

#define ll int

class Solution {
public:
    
    ll findPar(ll u, vector<ll> &par)
    {
        if(par[u]==u)
            return u;
        return findPar(par[u],par);
    }
    
    int removeStones(vector<vector<int>>& stones) {
        vector<ll> par(stones.size());
        vector<ll> rank(stones.size());
        for(ll i=0;i<stones.size();i++)
            par[i] = i, rank[i] = 0;
        ll count = stones.size();
        for(ll i=0;i<stones.size();i++)
            for(ll j=i+1;j<stones.size();j++)
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1])
                {
                    ll p1 = findPar(i,par);
                    ll p2 = findPar(j,par);
                    if(p1!=p2){
                        if(rank[p1]<rank[p2])
                            par[p1] = p2;
                        else if(rank[p1]>rank[p2])
                            par[p2] = p1;
                        else
                            par[p2] = p1, rank[p1]++;
                        count--;
                    }

                }
        return stones.size()-count;
    }
};