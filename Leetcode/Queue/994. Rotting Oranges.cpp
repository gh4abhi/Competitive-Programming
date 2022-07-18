// Problem Link - https://leetcode.com/problems/rotting-oranges/

#define ll int

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<ll,ll>> q;
        ll count = 0;
        for(auto i:grid)
            for(auto j:i)
                if(j==1)
                    count++;
        if(count==0)
            return 0;
        for(ll i=0;i<grid.size();i++)
            for(ll j=0;j<grid[0].size();j++)
                if(grid[i][j]==2)
                    q.push({i,j});
        q.push({-1,-1});
        ll ans = 0;
        vector<vector<ll>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        while(q.size())
        {
            pair<ll,ll> cur = q.front();
            q.pop();
            if(cur.first==-1 and cur.second==-1)
            {
                if(count>=0)
                    ans++;
                if(count==0)
                    break;
                if(q.size()==0)
                    break;
                q.push({-1,-1});
                continue;
            }
            for(auto i:dir)
            {
                if(cur.first+i[0]>=0 and cur.first+i[0]<grid.size() and cur.second+i[1]>=0 and cur.second+i[1]<grid[0].size())
                {
                    if(grid[i[0]+cur.first][i[1]+cur.second]==1)
                    {
                        grid[i[0]+cur.first][i[1]+cur.second]=2;
                        count--;
                        q.push({i[0]+cur.first,i[1]+cur.second});
                    }
                }
            }
        }
        if(count>0)
            return -1;
        return ans;
    }
};