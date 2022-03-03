// Problem Link - https://leetcode.com/problems/is-graph-bipartite/

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