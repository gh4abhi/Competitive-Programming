// Problem Link - https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

ll dp[101][10001];
bool canPart(vector<ll>& arr, ll n, ll target, ll ind)
{
    if(target==0)
        return 0;
    if(ind==n-1)
        return arr[ind]==target;
    if(dp[ind][target]!=-1)
        return dp[ind][target];
    bool one = canPart(arr,n,target,ind+1);
    bool two = false;
    if(arr[ind]<=target)
        two = canPart(arr,n,target-arr[ind],ind+1);
    return dp[ind][target] = one or two;
}    
    
bool canPartition(vector<int> &arr, int n)
{
    memset(dp,-1,sizeof(dp));
    ll sum = 0;
    for(ll i=0;i<n;i++)
        sum += arr[i];
    if(sum&1)
        return false;
    ll target = sum/2;
    return canPart(arr,n,target,0);
}
