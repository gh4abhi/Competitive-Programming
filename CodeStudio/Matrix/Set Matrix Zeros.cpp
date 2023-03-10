// Problem Link - https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int
void setZeros(vector<vector<int>> &matrix)
{
    ll m = matrix.size();
    ll n = matrix[0].size();
    ll op = 1;
    for(ll i=0;i<m;i++)
    {
        if(matrix[i][0]==0)
            op = 0;
        for(ll j=1;j<n;j++)
            if(matrix[i][j]==0)
                matrix[i][0] = 0, matrix[0][j] = 0;
    }
    for(ll i=m-1;i>=0;i--)
    {
        for(ll j=n-1;j>=1;j--)
            if(matrix[i][0]==0 or matrix[0][j]==0)
                matrix[i][j] = 0;
        if(op==0)
            matrix[i][0] = 0;
    }
}