// Problem Link - https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph

#define ll int

class Solution {
  public:
  
    void DFS(ll src, vector<vector<pair<ll,ll>>> &adj, vector<ll> &vis, stack<ll> &st)
    {
        vis[src] = 1;
        for(auto i:adj[src])
            if(vis[i.first]==0)
                DFS(i.first,adj,vis,st);
        st.push(src);
    }
    
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        vector<ll> vis(n,0);
        vector<ll> dis(n,INT_MAX);
        stack<ll> st;
        vector<vector<pair<ll,ll>>> adj(n);
        for(auto i:edges)
            adj[i[0]].push_back({i[1],i[2]});
        for(ll i=0;i<n;i++)
            if(vis[i]==0)
                DFS(i,adj,vis,st);
        dis[0] = 0;
        while(st.size())
        {
            auto cur = st.top();
            st.pop();
            if(dis[cur]!=INT_MAX)
                for(auto i:adj[cur])
                    dis[i.first] = min(dis[i.first],dis[cur] + i.second);
        }
        for(auto &i:dis)
            if(i==INT_MAX)
                i = -1;
        return dis;
     }
};