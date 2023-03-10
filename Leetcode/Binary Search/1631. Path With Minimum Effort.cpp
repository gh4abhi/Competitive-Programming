// Problem Link - https://leetcode.com/problems/path-with-minimum-effort/

#define ll int

class Solution {
public:
    ll vis[105][105];
    vector<pair<ll,ll>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void DFS(vector<vector<int>>& heights, ll mid, ll x, ll y)
    {
        if(vis[x][y])
            return;
        vis[x][y] = 1;
        ll m = heights.size(), n = heights[0].size();
        for(ll i=0;i<4;i++)
        {
            ll X = x + dir[i].first;
            ll Y = y + dir[i].second;
            if(X<0 or X>=m or Y<0 or Y>=n)
                continue;
            if(abs(heights[x][y]-heights[X][Y])<=mid)
                DFS(heights,mid,X,Y);
        }
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        ll start = 0, end = 1e9;
        ll m = heights.size(), n = heights[0].size();
        while(start<end)
        {
            ll mid = start + (end-start)/2;
            memset(vis,0,sizeof(vis));
            DFS(heights,mid,0,0);
            if(vis[m-1][n-1]==1)
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
};