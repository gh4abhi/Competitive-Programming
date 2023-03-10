// Problem Link - https://leetcode.com/problems/course-schedule-iv/

#define ll int

class Solution {
public:
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<ll> inDegree(numCourses,0);
        vector<vector<ll>> adj(numCourses);
        for(auto i:prerequisites)
            adj[i[0]].push_back(i[1]), inDegree[i[1]]++;
        vector<vector<ll>> adjMat(numCourses,vector<ll>(numCourses,0));
        vector<bool> ans;
        queue<ll> q;
        for(ll i=0;i<numCourses;i++)
            if(inDegree[i]==0)
                q.push(i);
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            for(auto i:adj[cur])
            {
                for(ll j=0;j<numCourses;j++)
                    if(adjMat[cur][j]==1)
                        adjMat[i][j] = 1;
                adjMat[i][cur] = 1;
                inDegree[i]--;
                if(inDegree[i]==0)
                    q.push(i);
            }
        }
        for(auto i:queries)
            ans.push_back(adjMat[i[1]][i[0]]);
        return ans;
    }
};