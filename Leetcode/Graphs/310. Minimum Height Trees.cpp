// Problem Link - https://leetcode.com/problems/minimum-height-trees/

#define ll int

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<ll> ans;
        queue<ll> q;
        vector<vector<ll>> adj(n);
        vector<ll> inDegree(n,0);
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            inDegree[i[0]]++;
            inDegree[i[1]]++;
        }
        for(ll i=0;i<n;i++)
            if(inDegree[i]==1)
                q.push(i);
        while(q.size())
        {
            ll sz = q.size();
            ans.clear();
            for(ll i=0;i<sz;i++)
            {
                auto cur = q.front();
                ans.push_back(cur);
                q.pop();
                for(auto j:adj[cur])
                {
                    inDegree[j]--;
                    if(inDegree[j]==1)
                        q.push(j);
                }
            }
        }
        if(n==1)
            ans.push_back(0);
        return ans;
    }
};