// Problem Link - https://www.codingninjas.com/codestudio/problems/982938?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int
#include<bits/stdc++.h>

void DFS(ll start, vector<vector<ll>> &adj, vector<ll> &vis, stack<ll> &st)
{
    vis[start] = 1;
    for(auto i:adj[start])
        if(vis[i]==0)
            DFS(i,adj,vis,st);
    st.push(start);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    stack<ll> st;
    vector<ll> vis(v,0);
    vector<vector<ll>> adj(v);
    for(auto i:edges)
        adj[i[0]].push_back(i[1]);
    for(ll i=0;i<v;i++)
        if(vis[i]==0)
            DFS(i,adj,vis,st);
    vector<ll> ans;
    while(st.size())
        ans.push_back(st.top()), st.pop();
    return ans;
}
