// Problem Link - https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

#define ll int

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<ll> inDegree(n,0);
        vector<vector<ll>> adj(n);
        for(auto i:edges)
            adj[i[0]].push_back(i[1]), inDegree[i[1]]++;
        vector<set<ll>> adjMat(n);
        queue<ll> q;
        for(ll i=0;i<n;i++)
            if(inDegree[i]==0)
                q.push(i);
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            for(auto i:adj[cur])
            {
                for(ll j=0;j<n;j++)
                    if(adjMat[cur].find(j)!=adjMat[cur].end())
                        adjMat[i].insert(j);
                adjMat[i].insert(cur);
                inDegree[i]--;
                if(inDegree[i]==0)
                    q.push(i);
            }
        }
        vector<vector<ll>> ans(n);
        for(ll i=0;i<n;i++)
            ans[i] = vector<ll>(adjMat[i].begin(),adjMat[i].end());
        return ans;
    }
};