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
    vector<ll> dp(target+1,0);
    dp[0] = 1;
    if(target<=arr[0])
        dp[arr[0]] = 1;
    for(ll i=1;i<n;i++)
    {
        vector<ll> temp = dp;
        for(ll j=1;j<target+1;j++)
        {
            dp[j] = temp[j];
            if(j>=arr[i])
                dp[j] = dp[j] or temp[j-arr[i]];
        }
    }
    return dp[target];
}
