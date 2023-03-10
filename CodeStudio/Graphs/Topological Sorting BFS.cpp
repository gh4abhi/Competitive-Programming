// Problem Link - https://www.codingninjas.com/codestudio/problems/topological-sorting_973003?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int n) {
    vector<ll> ans;
    queue<ll> q;
    vector<ll> indegree(n,0);
    vector<vector<ll>> adj(n);
    for(auto i:graph)
        adj[i[0]].push_back(i[1]), indegree[i[1]]++;
    for(ll i=0; i<n;i++)
        if(indegree[i]==0)
            q.push(i);
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(auto i:adj[cur])
        {
            indegree[i]--;
            if(indegree[i]==0)
                q.push(i);
        }
    }
    return ans;
}
