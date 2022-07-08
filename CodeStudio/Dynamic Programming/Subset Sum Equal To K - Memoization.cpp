// Problem Link - https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

ll dp[1000][1000];

bool subSum(ll n,vector<ll>& arr, ll target, ll ind)
{
    if(target==0)
        return true;
    if(ind==n-1)
        return target==arr[n-1];
    if(dp[ind][target]!=-1)
        return dp[ind][target];
    bool one = false;
    if(target>=arr[ind])
        one = subSum(n,arr,target-arr[ind],ind+1);
    bool two = subSum(n,arr,target,ind+1);
    return dp[ind][target] = one or two;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    memset(dp,-1,sizeof(dp));
    return subSum(n,arr,k,0);
}