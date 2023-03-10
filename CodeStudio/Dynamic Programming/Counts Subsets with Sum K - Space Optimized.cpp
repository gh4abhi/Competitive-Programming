// Problem Link - https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long
int findWays(vector<int> &num, int tar)
{
    vector<ll> dp(tar+1,0);
    dp[0] = 1;
    if(num[0]<=tar)
        dp[num[0]] = 1;
    for(ll i=1;i<num.size();i++)
    {
        vector<ll> temp = dp;
        for(ll j=1;j<tar+1;j++)
        {
            dp[j] = 0;
            dp[j] += temp[j];
            if(j>=num[i])
                dp[j] += temp[j-num[i]];
        }
    }
    return dp[tar];
}