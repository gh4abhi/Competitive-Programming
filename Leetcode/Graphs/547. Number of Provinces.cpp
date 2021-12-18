// Problem Link - https://leetcode.com/problems/number-of-provinces/

#define ll int

class Solution {
public:
    
    void findCircleNumBFSHelper(vector<vector<int>>& isConnected, ll source, vector<bool>& visited)
    {
        queue<ll> pendingNodes;
        pendingNodes.push(source);
        visited[source] = true;
        while(pendingNodes.size()!=0)
        {
            ll current = pendingNodes.front();
            pendingNodes.pop();
            for(ll i=0;i<isConnected.size();i++)
            {
                if(isConnected[current][i]==1 and visited[i]==false and i!=source)
                {
                    visited[i] = true;
                    pendingNodes.push(i);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
       vector<bool> visited(isConnected.size());
       for(ll i=0;i<isConnected.size();i++)
        {
            visited[i] = false;
        }
        ll count = 0;
        for(ll i=0;i<isConnected.size();i++)
        {
            if(!visited[i])
            {
                findCircleNumBFSHelper(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }
};
