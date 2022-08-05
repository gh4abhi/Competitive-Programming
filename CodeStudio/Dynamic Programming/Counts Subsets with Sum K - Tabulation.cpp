// Problem Link - https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long
int findWays(vector<int> &num, int tar)
{
    vector<vector<ll>> dp(num.size(),vector<ll>(tar+1,0));
    for(ll i=0;i<num.size();i++)
        dp[i][0] = 1;
    if(num[0]<=tar)
        dp[0][num[0]] = 1;
    for(ll i=1;i<num.size();i++)
    {
        for(ll j=1;j<tar+1;j++)
        {
            dp[i][j] += dp[i-1][j];
            if(j>=num[i])
                dp[i][j] += dp[i-1][j-num[i]];
        }
    }
    return dp[num.size()-1][tar];
}