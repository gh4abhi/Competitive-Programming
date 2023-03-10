// Problem Link - https://www.codingninjas.com/codestudio/problems/1062626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

ll DFS(ll start, map<ll,ll> &vis, map<ll,vector<ll>> &adj, map<ll,ll> &dfsVis)
{
    vis[start] = 1;
    dfsVis[start] = 1;
    for(auto i:adj[start])
    {
        if(vis[i]==0)
        {
            if(DFS(i,vis,adj,dfsVis))
                return 1;
        }
        else
        {
            if(dfsVis[i]==1)
                return 1;
        }
    }
    dfsVis[start] = 0;
    return 0;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
   map<ll,ll> vis;
   map<ll,ll> dfsVis;
   map<ll,vector<ll>> adj;
   for(auto i:edges)
       adj[i.first].push_back(i.second);
   for(ll i=1;i<=n;i++)
       if(vis[i]==0)
           if(DFS(i,vis,adj,dfsVis))
               return true;
    return false;
}