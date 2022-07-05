// Problem Link - https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

#include<bits/stdc++.h>
#define ll int

ll dp[101][101];
ll maxPath(vector<vector<int>> &matrix, ll i, ll j)
{
    if(j<0 or j>matrix[0].size()-1)
        return -1e9;
    if(i==matrix.size()-1)
        return matrix[i][j];
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll one = maxPath(matrix,i+1,j);
    ll two = maxPath(matrix,i+1,j+1);
    ll three = maxPath(matrix,i+1,j-1);
    return dp[i][j] = matrix[i][j] + max(one,max(two,three));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    ll ans = -1e9;
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<matrix[0].size();i++)
        ans = max(ans,maxPath(matrix,0,i));
    return ans;
}