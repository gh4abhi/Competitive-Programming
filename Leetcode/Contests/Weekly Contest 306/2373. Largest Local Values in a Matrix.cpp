// Problem Link - https://leetcode.com/contest/weekly-contest-306/problems/largest-local-values-in-a-matrix/

#define ll int

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        ll n = grid.size();
        ll m = grid[0].size();
        vector<vector<ll>> vect(n-2);
        for(ll i=0;i<n-2;i++)
        {
            for(ll j=0;j<m-2;j++)
            {
                ll maxi = -1e9;
                for(ll k=i;k<i+3;k++)
                {
                    for(ll z = j;z<j+3;z++)
                    {
                        maxi = max(maxi,grid[k][z]);   
                    }
                }
                vect[i].push_back(maxi);
            }
        }
        return vect;
    }
};