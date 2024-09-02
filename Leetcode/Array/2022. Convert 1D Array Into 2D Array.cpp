// Problem Link - https://leetcode.com/problems/convert-1d-array-into-2d-array/

#define ll int

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<ll>> ans(m,vector<ll>(n,0));
        ll i = 0, j = 0;
        for(ll ind=0;ind<original.size();ind++)
        {
            if(i>=m)
                return {};
            ans[i][j%n] = original[ind], j++, i = j/n;
        }
        if((j%n)!=0 or (i!=m))
            return {};
        return ans;
    }
};
