// Problem Link - https://www.codingninjas.com/codestudio/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int targetSum(int n, int d, vector<int>& arr) {
    ll sum = 0;
    for(auto i:arr)
        sum += i;
    if((sum-d)&1)
        return 0;
    vector<vector<ll>> dp(n,vector<ll>(sum+1,0));
    if(arr[0]==0)
        dp[0][0] = 2;
    else 
        dp[0][0] = 1;
    if(arr[0]<=sum and arr[0]!=0)
        dp[0][arr[0]] = 1;
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<sum+1;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(arr[i]<=j)
                dp[i][j] += dp[i-1][j-arr[i]];
        }
    }
    return dp[n-1][(sum-d)/2];
}
