// Problem Link - https://www.codingninjas.com/codestudio/problems/topological-sort_985252?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

vector<int> topologicalSort(vector<pair<int,int>>& edges, int n, int m)
{
    vector<ll> ans;
    vector<ll> indegree(n,0);
    vector<vector<ll>> adj(n);
    for(auto i:edges)
        adj[i.first-1].push_back(i.second-1), indegree[i.second-1]++;
    stack<ll> st;
    for(ll i=0;i<n;i++)
        if(indegree[i]==0)
            st.push(i);
    while(st.size())
    {
        auto cur = st.top();
        st.pop();
        ans.push_back(cur+1);
        for(auto i:adj[cur])
        {
            indegree[i]--;
            if(indegree[i]==0)
                st.push(i);
        }
    }
    return ans;
} 
