// Problem Link - https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int
int uniquePaths(int A, int B) {
    ll dp[B];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<B;i++)
        dp[i] = 1;
    for(ll i=1;i<A;i++)
        for(ll j=1;j<B;j++)
        {
            ll cur = dp[j] + dp[j-1];
            dp[j] = cur;
        }
    return dp[B-1];
}