// Problem Link - https://leetcode.com/problems/toeplitz-matrix/

#define ll int

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        ll m = matrix.size();
        ll n = matrix[0].size();
        for(ll i=1;i<m;i++)
            for(ll j=1;j<n;j++)
                if(matrix[i-1][j-1]!=matrix[i][j])
                    return false;
        return true;
    }
};