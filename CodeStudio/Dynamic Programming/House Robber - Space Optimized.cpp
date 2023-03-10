// Problem Link - https://www.codingninjas.com/codestudio/problems/loot-houses_630510?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int maxMoneyLooted(vector<int> &houses, int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return houses[0];
    ll a = houses[0];
    ll b = max(a,houses[1]);
    for(ll i=2;i<n;i++)
    {
        ll cur = max(b,a+houses[i]);        
        a = b;
        b = cur;
    }
    return b;
}