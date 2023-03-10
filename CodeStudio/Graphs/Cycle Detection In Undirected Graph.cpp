// Problem Link - https://www.codingninjas.com/codestudio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

bool DFS(ll cur, vector<ll> &vis, vector<vector<ll>> &adj, ll pre)
{
    vis[cur] = 1;
    for(auto i:adj[cur])
    {
        if(vis[i]==1)
        {
            if(i!=pre)
                return true;
        }
        else
        {
            if(DFS(i,vis,adj,cur))
                return true;
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
            if(DFS(i,vis,adj,-1))
                return "Yes";
    return "No";
}
