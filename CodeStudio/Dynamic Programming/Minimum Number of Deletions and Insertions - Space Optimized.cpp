// Problem Link - https://www.codingninjas.com/codestudio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

int canYouMake(string &str, string &ptr)
{
    ll m = str.length(), n = ptr.length();
    vector<ll> dp(ptr.length()+1,0), temp;
    for(ll i=1;i<m+1;i++)
    {
        temp = dp;
        for(ll j=1;j<n+1;j++)
        {
            if(str[i-1]==ptr[j-1])
                dp[j] = 1 + temp[j-1];
            else
                dp[j] = max(temp[j],dp[j-1]);
        }
    }
    return m+n-2*dp[n];
}