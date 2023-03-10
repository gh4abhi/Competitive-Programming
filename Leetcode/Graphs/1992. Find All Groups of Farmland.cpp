// Problem Link - https://leetcode.com/problems/find-all-groups-of-farmland/

#define ll int

class Solution {
    private :
    pair<ll,ll> findFarmlandHelper(vector<vector<int>>& land, ll i, ll j, vector<vector<bool>>& vis)
    {
        vis[i][j] = true;
        ll flag = 0;
        pair<ll,ll> ans = {-1,-1};
        if(i<land.size()-1 and vis[i+1][j]==false and land[i+1][j]!=0)
        {
            flag = 1;
            pair<ll,ll> l;
            l = findFarmlandHelper(land, i+1, j, vis);
            if(l.first>ans.first)
                ans = l;
        }
        if(j<land[0].size()-1 and vis[i][j+1]==false and land[i][j+1]!=0)
        {
            flag = 1;
             pair<ll,ll> l;
             l = findFarmlandHelper(land, i, j+1, vis);
            if(l.first>ans.first)
                ans = l;
        }
        if(flag==0)
        return {i,j};
        return ans;
    }
    public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<bool>> vis(land.size(), vector<bool>(land[0].size(),false));
        vector<vector<int>> ans;
        for(ll i=0;i<land.size();i++)
        {
            for(ll j=0;j<land[i].size();j++)
            {
                if(!vis[i][j] and land[i][j]==1)
                {
                    pair<ll,ll> tempAns = findFarmlandHelper(land, i, j, vis);
                    vector<ll> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(tempAns.first);
                    temp.push_back(tempAns.second);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};