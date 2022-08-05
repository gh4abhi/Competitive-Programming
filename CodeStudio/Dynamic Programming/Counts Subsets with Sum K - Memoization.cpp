// Problem Link - https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long
ll dp[100][10000];
ll find(vector<int> &num, int tar, ll ind)
{
    if(tar==0)
        return 1;
    if(ind==num.size()-1)
        return num[ind]==tar;
    ll pick = 0;
    if(dp[ind][tar]!=-1)
        return dp[ind][tar];
    if(num[ind]<=tar)
        pick = find(num,tar-num[ind],ind+1);
    ll notPick = find(num,tar,ind+1);
    return dp[ind][tar] = pick + notPick;
}

int findWays(vector<int> &num, int tar)
{
    memset(dp,-1,sizeof(dp));
    return find(num,tar,0);
}