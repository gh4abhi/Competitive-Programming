// Problem Link - https://leetcode.com/contest/weekly-contest-303/problems/equal-row-and-column-pairs/

#define ll long long

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<ll>,ll> m1,m2;
        for(ll i=0;i<grid.size();i++)
        {
            vector<ll> temp;
            for(ll j=0;j<grid[0].size();j++)
            {
                temp.push_back(grid[i][j]);
            }
            m1[temp]++;
        }        for(ll j=0;j<grid[0].size();j++)
        {
            vector<ll> temp;
            for(ll i=0;i<grid.size();i++)
            {
                temp.push_back(grid[i][j]);
            }
            m2[temp]++;
        }
        ll ans = 0;
        for(auto i:m1)
        {
            ans += i.second*(m2[i.first]); 
        }
        return (int)ans;
    }
};