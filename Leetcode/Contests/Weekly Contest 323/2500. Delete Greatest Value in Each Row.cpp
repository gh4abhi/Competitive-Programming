// Problem Link - https://leetcode.com/contest/weekly-contest-323/problems/delete-greatest-value-in-each-row/

#define ll int

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(auto &i:grid)
            sort(i.begin(),i.end());
        ll ans = 0;
        for(ll j=0;j<grid[0].size();j++)
        {
            ll maxi = INT_MIN;
            for(ll i=0;i<grid.size();i++)
                maxi = max(maxi,grid[i][j]);
            ans += maxi;
        }
        return ans;
    }
};