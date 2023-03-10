// Problem Link - https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

bool subsetSumToK(int n, int target, vector<int> &arr) {
    vector<bool> dp(target+1,0);
    dp[0] = 1;
    dp[arr[0]] = 1;
    for(ll i=1;i<n;i++)
    {
        vector<bool> temp = dp;
        for(ll j=1;j<target+1;j++)
        {
            dp[j] = temp[j];
            if(arr[i]<=j)
                dp[j] = dp[j] or temp[j-arr[i]];
        }
    }
    return dp[target];
}