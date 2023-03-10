// Problem Link - https://leetcode.com/problems/path-with-maximum-probability/

#define ll int

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<ll,double>>> adj(n);
        for(ll i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<ll,ll>> pq;
        pq.push({0,start});
        vector<double> success(n,0);
        success[start] = 1;
        while(pq.size())
        {
            auto cur = pq.top();
            pq.pop();
            for(auto i:adj[cur.second])
                if(success[cur.second]*i.second>success[i.first])
                    success[i.first] = success[cur.second]*i.second, pq.push({success[i.first],i.first});
        }
        return success[end];
    }
};