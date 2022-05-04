// Problem Link - https://leetcode.com/problems/course-schedule-ii/

#define ll int
class Solution {
public:
    bool detectCycle(ll source, ll numCourses, vector<ll>& vis, vector<ll>& dfsVis,vector<vector<ll>>& adj)
    {
        vis[source] = 1;
        dfsVis[source] = 1;
        for(auto i:adj[source])
        {
            if(!vis[i])
            {
                if(detectCycle(i,numCourses,vis,dfsVis,adj))
                    return true;
            }
            else
            {
                if(dfsVis[i])
                    return true;
            }
        }
        dfsVis[source] = 0;
        return false;
    }
void topologicalSortDFSHelper(ll source, ll nodesNum, vector<vector<ll>>& adj, stack<ll>& st, vector<ll>& vis)
{
    vis[source] = 1;
    for(ll i=0;i<nodesNum;i++)
        for(auto i:adj[source])
            if(!vis[i])
            topologicalSortDFSHelper(i,nodesNum,adj,st,vis);
    st.push(source);
}
    vector<int> findOrder(int nodesNum, vector<vector<int>>& edges) {
        vector<vector<ll>> adj(nodesNum);
        vector<ll> topoSort;
        for(auto i:edges)
            adj[i[1]].push_back(i[0]);
        vector<ll> vis(nodesNum,0);
        vector<ll> dfsVis(nodesNum,0);
        for(ll i=0;i<nodesNum;i++)
            if(!vis[i])
                if(detectCycle(i,nodesNum,vis,dfsVis,adj))
                    return topoSort;
        stack<ll> st;
        for(ll i=0;i<vis.size();i++)
            vis[i] = 0;
        for(ll i=0;i<nodesNum;i++)
        if(!vis[i])
            topologicalSortDFSHelper(i,nodesNum,adj,st,vis);
    while(st.size())
        topoSort.push_back(st.top()), st.pop();
    return topoSort;
    }
};