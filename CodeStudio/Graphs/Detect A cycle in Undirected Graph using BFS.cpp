// Problem Link - https://www.codingninjas.com/codestudio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

bool BFS(ll start, vector<vector<ll>> &adj, vector<ll> &vis)
{
    queue<pair<ll,ll>> q;
    q.push({start,-1});
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        vis[cur.first] = 1;
        for(auto i:adj[cur.first])
        {
            if(vis[i]==0)
                q.push({i,cur.first});
            else
            {
                if(i!=cur.second)
                    return true;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<ll>> adj(n);
    for(auto i:edges)
    {
        adj[i[0]-1].push_back(i[1]-1);
        adj[i[1]-1].push_back(i[0]-1);
    }
    vector<ll> vis(n,0);
    for(ll i=0;i<n;i++)
        if(vis[i]==0)
            if(BFS(i,adj,vis))
                return "Yes";
    return "No";
}
