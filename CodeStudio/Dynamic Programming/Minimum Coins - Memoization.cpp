// Problem Link - https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

ll miniEle(vector<int> &num, ll sum, ll ind, vector<vector<ll>> &dp)
{
    if(ind==0)
    {
        if(sum%num[0]==0)
            return sum/num[0];
        return 1e9;
    }
    if(dp[ind][sum]!=-1)
        return dp[ind][sum];
    ll notTake = miniEle(num,sum,ind-1,dp);
    ll take = 1e9;
    if(sum-num[ind]>=0)
        take = 1 + miniEle(num,sum-num[ind],ind,dp);
    return dp[ind][sum] = min(take,notTake);
}

int minimumElements(vector<int> &num, int x)
{
    vector<vector<ll>> dp(num.size(),vector<ll>(x+1,-1));
    ll ans = miniEle(num,x,num.size()-1,dp);
    if(ans>=1e9)
        return -1;
    return ans;
}