// Problem Link - https://www.codingninjas.com/codestudio/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

ll dp[26][100000];
ll tarSum(ll n, ll target, vector<int>&arr, ll ind, ll sum)
{
    if(ind==0)
    {
        if(sum==target and arr[0]==0)
            return 2;
        if(sum + arr[ind] == target or sum - arr[ind] == target)
            return 1;
        return 0;
    }
    if(dp[ind][sum]!=-1)
        return dp[ind][sum];
    ll a = tarSum(n,target,arr,ind-1,sum-arr[ind]);
    ll b =  tarSum(n,target,arr,ind-1, sum + arr[ind]);
    return dp[ind][sum] = a+b;
}

int targetSum(int n, int target, vector<int>& arr) {
    memset(dp,-1,sizeof(dp));
    return tarSum(n,target,arr,n-1,0);
}
