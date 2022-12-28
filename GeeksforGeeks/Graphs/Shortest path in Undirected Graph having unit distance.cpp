// Problem Link - https://practice.geeksforgeeks.org/problems/a-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance

#define ll int

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        vector<ll> vis(n,0);
        vector<ll> dis(n,INT_MAX);
        vector<vector<ll>> adj(n);
        for(auto i:edges)
            adj[i[0]].push_back(i[1]), adj[i[1]].push_back(i[0]);
        queue<ll> q;
        q.push(src);
        dis[src] = 0;
        vis[src] = 1;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            for(auto i:adj[cur])
            { 
                if(vis[i]==0)
                    q.push(i),dis[i] = min(dis[i],1+dis[cur]), vis[i] = 1;
                else
                    dis[i] = min(dis[i],1+dis[cur]);
            }
        }
        for(auto &i:dis)
            if(i==INT_MAX)
                i = -1;
        return dis;
    }
};
