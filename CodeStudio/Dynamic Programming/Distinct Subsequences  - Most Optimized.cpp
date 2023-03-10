// Problem Link - https://www.codingninjas.com/codestudio/problems/subsequence-counting_3755256?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int
#define MOD 1000000007
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<ll> dp(ls+1,0);
    dp[0] = 1;
    for(ll i=1;i<lt+1;i++)
    {
        for(ll j=ls;j>=1;j--)
        {
            if(t[i-1]==s[j-1])
                dp[j] = (dp[j-1] + dp[j])%MOD;
        }
    }
    return dp[ls];
} 