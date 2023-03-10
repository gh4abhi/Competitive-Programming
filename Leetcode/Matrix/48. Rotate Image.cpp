// Problem Link - https://leetcode.com/problems/rotate-image/

#define ll int

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        ll m = matrix.size();
        ll n = matrix[0].size();
        for(ll i=0;i<m;i++)
            for(ll j=0;j<i;j++)
                swap(matrix[i][j],matrix[j][i]);
        for(ll i=0;i<m;i++)
        {
            ll start = 0, end = n-1;
            while(start<=end)
                swap(matrix[i][start],matrix[i][end]), start++, end--;
        }
    }
};