// Problem Link - https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int minEng(ll ind, vector<int> &heights, vector<ll>& dp)
{
    if(ind==0)
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];
    ll first = minEng(ind-1,heights,dp) + abs(heights[ind] - heights[ind-1]);
    ll second = INT_MAX;
    if(ind>1)
        second = minEng(ind-2,heights,dp) + abs(heights[ind] - heights[ind-2]);
    dp[ind] = min(first,second);
    return dp[ind];
}
int frogJump(int n, vector<int> &heights)
{
    vector<ll> dp(n,-1);
    return minEng(n-1,heights,dp);
}