// Problem Link - https://leetcode.com/problems/keys-and-rooms/

#define ll int

class Solution {
public:
    void DFS(ll src, vector<vector<ll>>& rooms, vector<ll> &vis)
    {
        vis[src] = 1;
        for(auto i:rooms[src])
            if(vis[i]==0)
                DFS(i,rooms,vis);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       ll n = rooms.size();
       vector<ll> vis(n,0);
       DFS(0,rooms,vis);
       for(auto i:vis)
           if(!i)
               return false;
        return true;
    }
};