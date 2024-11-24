// problem Link - https://leetcode.com/problems/maximum-matrix-sum/?envType=daily-question&envId=2024-11-24
#define ll long long

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll a = 0, b = 0, c = 0, f = INT_MAX;
        for (ll i = 0; i < matrix.size(); i++)
            for (ll j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] > 0)
                    a += matrix[i][j];
                else
                    b += abs(matrix[i][j]), c++;
                f = min(f, (ll)abs(matrix[i][j]));
            }
        if (c & 1)
            return a + b - 2 * f;
        return a + b;
    }
};