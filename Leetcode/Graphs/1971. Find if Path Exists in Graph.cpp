// Problem Link - https://leetcode.com/problems/find-if-path-exists-in-graph/

// Depth First Search Approach

#define ll int
class Solution {
public:
    
    bool dfs(int n, vector<vector<int>> &adjList, int start, int end, vector<bool> &visited)
    {
        if(start == end)
        {
            return true;
        }
        
        visited[start] = true;
        for(auto con:adjList[start])
        {
            if(visited[con]==false)
            {
                if(dfs(n,adjList, con, end, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
    vector<vector<int>> adjList(n);
        for(auto ed:edges)
        {
            adjList[ed[0]].push_back(ed[1]);
            adjList[ed[1]].push_back(ed[0]);
        }
    vector<bool> visited(n);
    for(ll i=0;i<n;i++)
    {
        visited[i] = false;
    }
    return dfs(n,adjList, start, end, visited);
    }
};

// Breadth First Search Approach

/*#define ll int
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int> adjList[n];
        for(auto i: edges)
        {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        
        queue<int> pendingNodes;
        pendingNodes.push(start);
        vector<bool> visited(n,false);
        visited[start] = false;
        while(pendingNodes.size()!=0)
        {
            ll cur = pendingNodes.front();
            if(cur==end)
            {
                return true;
            }
            pendingNodes.pop();
            for(auto i: adjList[cur])
            {
                if(!visited[i])
                {
                    pendingNodes.push(i);
                    visited[i] = true;
                }
            }
        }
        return false;
    }
};*/
