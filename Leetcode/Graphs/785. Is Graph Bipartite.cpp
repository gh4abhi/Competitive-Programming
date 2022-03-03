// Problem Link - https://leetcode.com/problems/is-graph-bipartite/

// BFS Approach

#define ll int

class Solution {
public:
    
bool isGraphBipartiteHelper(vector<vector<int>>&edges, ll nodesNum, ll source, vector<ll>& color)
{
    color[source] = 1;
    queue<ll> pendingNodes;
    pendingNodes.push(source);
    while(pendingNodes.size()!=0)
    {
        ll current = pendingNodes.front();
        pendingNodes.pop();
        for(auto i: edges[current])
        {
                if(color[i]==-1)
                   {
                        color[i] = !color[current];
                        pendingNodes.push(i);                   
                   }
                else
                {
                    if(color[i]==color[current])
                        return false;   
                }    
        }
    }
    return true;
}
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<ll> color(graph.size(),-1);
        ll nodesNum = graph.size();
        for(ll i=0;i<nodesNum;i++)
    {
        if(color[i]==-1)
        {
            if(!isGraphBipartiteHelper(graph, nodesNum, i, color))
                return false;
        }
    }
        return true;
    }
};

// DFS Approach

/*#define ll int

class Solution {
public:
    
bool isGraphBipartiteDFSHelper(vector<vector<int>>&edges, ll nodesNum, ll source, vector<ll>& color)
{
    for(auto i:edges[source])
    {
            if(color[i]==-1)
            {
                color[i] = 1 - color[source];
                if(!isGraphBipartiteDFSHelper(edges, nodesNum, i, color))
                    return false;
            }
            else
            {
                if(color[i]==color[source])
                    return false;   
            }
        }
    return true;
}
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<ll> color(graph.size(),-1);
        ll nodesNum = graph.size();
     for(ll i=0;i<nodesNum;i++)
    {
        if(color[i]==-1)
        {
            color[i] = 1;
            if(!isGraphBipartiteDFSHelper(graph, nodesNum, i, color))
                return false;
        }
    }    
    return true;
    }
};*/