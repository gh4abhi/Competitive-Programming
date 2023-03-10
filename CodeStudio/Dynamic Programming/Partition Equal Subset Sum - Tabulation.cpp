// Problem Link - https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

bool canPartition(vector<int> &arr, int n)
{
    ll sum = 0;
    for(ll i=0;i<n;i++)
        sum += arr[i];
    if(sum&1)
        return false;
    ll target = sum/2;
    vector<vector<ll>> dp(n,vector<ll>(target+1,0));
    for(ll i=0;i<n;i++)
        dp[i][0] = 1;
    if(target<=arr[0])
        dp[0][arr[0]] = 1;
    for(ll i=1;i<n;i++)
    {
        for(ll j=1;j<target+1;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=arr[i])
                dp[i][j] = dp[i][j] or dp[i-1][j-arr[i]];
        }
    }
    return dp[n-1][target];
}
