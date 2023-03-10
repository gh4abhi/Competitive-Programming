#define ll int

vector<vector<int>> solve(vector<vector<int>>& matrix) {
    vector<vector<ll>> ans(matrix.size(),vector<ll>(matrix[0].size(),0));
    ll r = 0, c = 0;
    for(ll i=0;i<matrix.size();i++)
    {
        for(ll j = matrix[0].size()-1;j>=0;j--)
        {
            ans[r][c] = matrix[i][j];
            r++;
            r = r%(matrix.size());
            c = c%matrix[0].size();    
        }
        c++;
    }
    return ans;
}
