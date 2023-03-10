// Problem Link - https://leetcode.com/contest/weekly-contest-287/problems/find-players-with-zero-or-one-losses/

#define ll int

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<ll,ll> vis;
        for(auto i:matches)
        {
            if(vis.count(i[0])==0)
                vis[i[0]] = 0;
            vis[i[1]]++;
        }
        vector<ll> win, oneL;
        for(auto i:vis)
        {
            if(i.second==0)
                win.push_back(i.first);
            else if(i.second==1)
                oneL.push_back(i.first);
        }
        vector<vector<ll>> ans;
        ans.push_back(win);
        ans.push_back(oneL);
        return ans;
    }
};