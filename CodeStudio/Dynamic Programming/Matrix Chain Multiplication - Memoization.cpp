// Problem Link - https://www.codingninjas.com/codestudio/problems/975344?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

ll matrixMulti(vector<ll> &arr, ll n, ll i, ll j,vector<vector<ll>> &dp)
{
    if(i==j)
        return 0;
    ll ans = INT_MAX;
    if(dp[i][j]!=-1)
        return dp[i][j];
    for(ll k=i;k<j;k++)
        ans = min(ans,arr[i-1]*arr[k]*arr[j] + matrixMulti(arr,n,i,k,dp) + matrixMulti(arr,n,k+1,j,dp));
    return dp[i][j] = ans;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<ll>> dp(N,vector<ll>(N,-1));
    return matrixMulti(arr,N,1,N-1,dp);
}