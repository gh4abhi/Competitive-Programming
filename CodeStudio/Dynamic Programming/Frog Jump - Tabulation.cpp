// Problem Link - https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int frogJump(int n, vector<int> &heights)
{
    vector<ll> dp(n,0);
    for(ll i=n-2;i>=0;i--)
    {
        ll first = dp[i+1] + abs(heights[i]-heights[i+1]);
        ll second = INT_MAX;
        if(i<n-2)
            second = dp[i+2] + abs(heights[i]-heights[i+2]);
        dp[i] = min(first,second);
     }
    return dp[0];
}