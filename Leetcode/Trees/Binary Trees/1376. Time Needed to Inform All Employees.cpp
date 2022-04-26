// Problem Link - https://leetcode.com/problems/time-needed-to-inform-all-employees/

#define ll int

class Solution {
public:
    
    ll DFS(map<ll,vector<ll>>&adjList, ll ind,  vector<int>& informTime)
    {
        if(adjList[ind].size()==0)
            return 0;
        ll ans = 0;
        for(auto i:adjList[ind])
            ans = max(ans,DFS(adjList,i,informTime));
        return informTime[ind] + ans;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)      {
        map<ll,vector<ll>> adjList;
        ll par = 0;
        for(ll i=0;i<manager.size();i++)
            if(manager[i]!=-1)
                adjList[manager[i]].push_back(i);
        return DFS(adjList,headID,informTime);
     }
};