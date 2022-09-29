// Problem Link - https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

bool check(string s1, string s2)
{
    if(s1.length()!=1+s2.length())
        return false;
    ll i=0,j=0;
    while(i<s1.length())
    {
        if(s1[i]==s2[j])
            i++,j++;
        else
            i++;
    }
    if(i==s1.length() and j==s2.length())
        return true;
    return false;
}

int longestStrChain(vector<string> &arr)
{
    ll n = arr.size();
    vector<ll> dp(n,1);
    ll ans = 1;
    sort(arr.begin(),arr.end(),[](string &a, string &b){
        return a.length()<b.length();
    });
    for(ll i=1;i<n;i++)
    {
        for(ll j=i-1;j>=0;j--)
        {
            if(check(arr[i],arr[j]) and dp[i]<1+dp[j])
                dp[i] = 1 + dp[j];
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}