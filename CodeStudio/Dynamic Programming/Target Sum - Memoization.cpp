// Problem Link - https://www.codingninjas.com/codestudio/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

ll tarSum(int n, int target, vector<int>& arr, ll ind, map<pair<ll,ll>, ll> & dp)
{
    if(ind==0)
    {
        if(target==0 and arr[0]==0)
            return 2;
        if(target==0 or target==arr[0])
            return 1;
        return 0;
    }
    if(dp.count({ind,target})!=0)
        return dp[{ind,target}];
    ll notTake = tarSum(n,target,arr,ind-1,dp);
    ll take = 0;
    if(target-arr[ind]>=0)
        take = tarSum(n,target-arr[ind],arr,ind-1,dp);
    return dp[{ind,target}] = take + notTake;
}

int targetSum(int n, int target, vector<int>& arr) {
    map<pair<ll,ll>,ll> dp;
    ll sum = 0;
    for(auto i:arr)
        sum += i;
    if((sum+target)&1)
        return 0;
    return tarSum(n,(sum+target)/2,arr,n-1,dp);
}