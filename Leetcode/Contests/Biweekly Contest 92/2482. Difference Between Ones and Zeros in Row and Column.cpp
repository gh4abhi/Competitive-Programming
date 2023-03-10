// Problem Link - https://leetcode.com/contest/biweekly-contest-92/problems/difference-between-ones-and-zeros-in-row-and-column/

#define ll int

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        ll m = grid.size();
        ll n = grid[0].size();
        map<ll,ll> r1,r0,c1,c0;
        for(ll i=0;i<m;i++)
        {
            ll one = 0, zero = 0;
            for(ll j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    one++;
                else
                    zero++;
            }
            r1[i] = one;
            r0[i] = zero;
        }
        for(ll j=0;j<n;j++)
        {
            ll one = 0, zero = 0;
            for(ll i=0;i<m;i++)
            {
                if(grid[i][j]==1)
                    one++;
                else
                    zero++;                
            }
            c1[j] = one;
            c0[j] = zero;
        }
        vector<vector<ll>> ans(m,vector<ll>(n,0));
        for(ll i=0;i<m;i++)
            for(ll j=0;j<n;j++)
                ans[i][j] = (r1[i]+c1[j]-r0[i]-c0[j]);
        return ans;
    }
};