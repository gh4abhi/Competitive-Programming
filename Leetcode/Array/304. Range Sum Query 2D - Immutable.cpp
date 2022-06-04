// Problem Link - https://leetcode.com/problems/range-sum-query-2d-immutable/

#define ll int

class NumMatrix {
public:
    
    vector<vector<ll>> mat;
    vector<vector<ll>> op;
    
    NumMatrix(vector<vector<int>>& matrix) {
        op = matrix;
        for(ll i=0;i<matrix.size();i++)
            for(ll j=1;j<matrix[0].size();j++)
                matrix[i][j] += matrix[i][j-1];
        mat = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        ll ans = 0;
        for(ll i=row1;i<=row2;i++)
            ans += (mat[i][col2]-mat[i][col1] + op[i][col1]);
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */