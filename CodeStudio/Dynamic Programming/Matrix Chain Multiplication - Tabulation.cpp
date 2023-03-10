// Problem Link - https://www.codingninjas.com/codestudio/problems/975344?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<ll>> dp(n,vector<ll>(n,INT_MAX));
    for(ll i=1;i<n;i++)
        dp[i][i] = 0;
    for(ll i=n-1;i>=1;i--)
        for(ll j=i+1;j<n;j++)
            for(ll k=i;k<j;k++)
                dp[i][j] = min(dp[i][j],arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j]);
    return dp[1][n-1];
}