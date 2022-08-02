// Problem Link - https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

 #define ll int

void DFS(map<ll,vector<ll>> &adj, map<ll,ll>& vis, ll start, vector<ll> &vect)
{
    vis[start] = 1;
    vect.push_back(start);
    for(auto i:adj[start])
        if(vis[i]==0)
            DFS(adj,vis,i,vect);
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    map<ll,vector<ll>> adj;
    for(auto i:edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<ll> vect;
    map<ll,ll> vis;
    for(ll i=0;i<V;i++)
    {
        if(vis[i]==0)
        {
            DFS(adj,vis,i,vect);
            ans.push_back(vect);
            vect.clear();
        }
    }
    return ans;
}