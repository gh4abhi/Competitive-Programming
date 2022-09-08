// Problem Link - https://www.codingninjas.com/codestudio/problems/subsequence-counting_3755256?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int
#define MOD 1000000007
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<vector<ll>> dp(lt+1,vector<ll>(ls+1,0));
    for(ll i=0;i<lt+1;i++)
        dp[i][0] = 1;
    for(ll i=1;i<lt+1;i++)
    {
        for(ll j=1;j<ls+1;j++)
        {
            if(t[i-1]==s[j-1])
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
            else
                dp[i][j] = dp[i-1][j]%MOD;
        }
    }
    return dp[lt][ls];
} 