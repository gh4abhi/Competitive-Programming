// Problem Link - https://leetcode.com/problems/course-schedule/

#define ll int

class Solution {
public:
    
    bool canFinishHelper(ll source, ll numCourses, vector<ll>& vis, vector<ll>& dfsVis, vector<vector<ll>>& adj)
    {
        vis[source] = 1;
        dfsVis[source] = 1;
        for(auto i:adj[source])
        {
            if(!vis[i])
            {
                if(canFinishHelper(i,numCourses,vis,dfsVis,adj))
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
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<ll>> adj(numCourses);
        for(auto i:prerequisites)
            adj[i[1]].push_back(i[0]);
        vector<ll> vis(numCourses,0);
        vector<ll> dfsVis(numCourses,0);
        for(ll i=0;i<numCourses;i++)
            if(!vis[i])
                if(canFinishHelper(i,numCourses,vis,dfsVis,adj))
                    return false;
        return true;
    }
};