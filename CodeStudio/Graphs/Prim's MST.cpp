// Problem Link - https://www.codingninjas.com/codestudio/problems/1095633?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<pair<ll,ll>>> adj(n);
    for(auto i:g)
    {
        adj[i.first.first-1].push_back({i.first.second-1,i.second});
        adj[i.first.second-1].push_back({i.first.first-1,i.second});
    }
    vector<ll> par(n,-1);
    vector<ll> mstSet(n,0);
    vector<ll> key(n,INT_MAX);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,0});
    key[0] = 0;
    par[0] = -1;
    while(pq.size())
    {
        ll u = pq.top().second;
        pq.pop();
        mstSet[u] = 1;
        for(auto i:adj[u])
        {
            ll v = i.first;
            ll w = i.second;
            if(mstSet[v]==0 and key[v]>w)
                par[v] = u, key[v] = w, pq.push({key[v],v});
        }
    }
    vector<pair<pair<ll,ll>,ll>> ans;
    for(ll i=1;i<n;i++)
        ans.push_back({{i+1,par[i]+1},key[i]});
    return ans;
}
