// Problem Link - https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

void BFS(ll start, map<ll,vector<ll>> &adj, map<ll,ll> &vis, vector<ll>& ans)
{
    queue<ll> q;
    q.push(start);
    while(q.size())
    {
        auto cur = q.front();
        ans.push_back(cur);
        vis[cur] = 1;
        q.pop();
        for(auto i:adj[cur])
            if(vis[i]==0)
            {
                vis[i] = 1;
                q.push(i);
            }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    map<ll,ll> vis;
    map<ll,vector<ll>> adj;
    for(auto i:edges)
    {
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }
    for(ll i=0;i<vertex;i++)
        sort(adj[i].begin(),adj[i].end());
    vector<ll> ans;
    for(ll i=0;i<vertex;i++)
    {
        if(vis[i]==0)
            BFS(i,adj,vis,ans);
    }
    return ans;
}