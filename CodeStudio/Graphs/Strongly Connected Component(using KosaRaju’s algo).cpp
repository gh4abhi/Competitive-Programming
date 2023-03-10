// Problem Link - https://www.codingninjas.com/codestudio/problems/985311?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

void topoSort(ll start, vector<vector<ll>> &adj, vector<ll> &vis, stack<ll> &st)
{
    vis[start] = 1;
    for(auto i:adj[start])
        if(vis[i]==0)
            topoSort(i,adj,vis,st);
    st.push(start);
}

void revDFS(ll start, vector<vector<ll>> &adj, vector<ll> &vis, vector<ll> &vect)
{
    vis[start] = 1;
    vect.push_back(start);
    for(auto i:adj[start])
       if(vis[i]==0)
           revDFS(i,adj,vis,vect);
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<ll>> adj(n);
    for(auto i:edges)
        adj[i[0]].push_back(i[1]);
    stack<ll> st;
    vector<ll> vis(n,0);
    for(ll i=0;i<n;i++)
        if(vis[i]==0)
            topoSort(i,adj,vis,st);
    vector<vector<ll>> transpose(n);
    for(ll i=0;i<n;i++)
    {
        vis[i] = 0;
        for(auto j:adj[i])
            transpose[j].push_back(i);
    }
    vector<vector<ll>> ans;
    while(st.size())
    {
        ll node = st.top();
        st.pop();
        if(vis[node]==0)
        {
            vector<ll> vect;
            revDFS(node,transpose,vis,vect);
            if(vect.size())
                ans.push_back(vect);
        }
    }
    return ans;
}