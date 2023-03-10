// PRoblem Link - https://www.codingninjas.com/codestudio/problems/1112624?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
    vector<ll> dp(n+1);
    dp[n] = 0;
    vector<ll> temp;
    ll ans = 0;
    for(ll i=n-1;i>=0;i--)
    {
        temp = dp;
        for(ll pre=-1;pre<i;pre++)
        {
            if(pre==-1 or arr[i]>arr[pre])
                dp[pre+1] = max(dp[pre+1],arr[i]+temp[i+1]);
            dp[pre+1] = max(dp[pre+1],temp[pre+1]);
        }
    }
    return dp[0];
}