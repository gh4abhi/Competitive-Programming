// Problem Link - https://www.codingninjas.com/codestudio/problems/920469?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

vector<int> dijkstra(vector<vector<int>> &vec, int n, int e, int source) {
    vector<vector<pair<ll,ll>>> adj(n);
    for(auto i:vec)
    {
        adj[i[0]].push_back({i[1],i[2]});
        adj[i[1]].push_back({i[0],i[2]});
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    vector<ll> dis(n,INT_MAX);
    dis[source] = 0;
    pq.push({0,source});
    while(pq.size())
    {
        auto cur = pq.top();
        pq.pop();
        for(auto i:adj[cur.second])
        {
            if(dis[cur.second] + i.second< dis[i.first])
                dis[i.first] = dis[cur.second] + i.second, pq.push({dis[cur.second] + i.second, i.first});
        }
    }
    return dis;
}
