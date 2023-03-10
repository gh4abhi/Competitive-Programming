// Problem Link - https://practice.geeksforgeeks.org/problems/articulation-point-1/1

#define ll int

class Solution {
  public:
  
    void DFS(ll src, ll par, ll timer, vector<ll> &tin, vector<ll> &low, vector<ll> &vis, vector<ll> &ans, vector<ll> adj[])
    {
        vis[src] =1;
        ll child = 0;
        tin[src] = low[src] = timer++;
        for(auto i: adj[src])
        {
            if(i==par)
                continue;
            if(vis[i]==0)
            {
                child++;
                DFS(i,src,timer,tin,low,vis,ans,adj);
                low[src] = min(low[src],low[i]);
                if(tin[src]<=low[i] and par!=-1)
                    ans[src] = 1;
            }
            else
                low[src] = min(low[src],low[i]);
        }
        if(par==-1 and child>1)
            ans[src] = 1;
    }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<ll> tin(V,-1);
        vector<ll> low(V,-1);
        vector<ll> vis(V,0);
        vector<ll> ans(V,0);
        ll timer = 0;
        for(ll i=0; i<V;i++)
            if(vis[i]==0)
                DFS(i,-1,timer,tin,low,vis,ans,adj);
        vector<ll> artPoint;
        for(ll i=0;i<V;i++)
            if(ans[i])
                artPoint.push_back(i);
        if(artPoint.size()==0)
            artPoint.push_back(-1);
        return artPoint;
    }
};