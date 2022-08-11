// Problem Link - https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

int minimumElements(vector<int> &num, int x)
{
    vector<vector<ll>> dp(num.size(),vector<ll>(x+1,0));
    for(ll i=0;i<=x;i++)
    {
        if(i%num[0]==0)
            dp[0][i] = i/num[0];
        else
            dp[0][i] = 1e9;
    }
    for(ll i=1;i<num.size();i++)
    {
        for(ll j=0;j<=x;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=num[i])
                dp[i][j] = min(dp[i][j],1+dp[i][j-num[i]]);
        }
    }
    ll ans =  dp[num.size()-1][x];
    if(ans>=1e9)
        return -1;
    return ans;
}