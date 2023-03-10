// Problem Link - https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int frogJump(int n, vector<int> &heights)
{
    ll one = 0, sec = 0;
    for(ll i=n-2;i>=0;i--)
    {
        ll first = one + abs(heights[i]-heights[i+1]);
        ll second = INT_MAX;
        if(i<n-2)
            second = sec + abs(heights[i]-heights[i+2]);
        ll cur = min(first,second); 
        sec = one;
        one = cur;
    }
    return one;
}