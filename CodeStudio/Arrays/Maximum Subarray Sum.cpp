// Problem Link - https://www.codingninjas.com/codestudio/problems/630526?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll long long
long long maxSubarraySum(int arr[], int n)
{
    ll ans = arr[0];
    ll sum = 0;
    for(ll i=0;i<n;i++)
    {
        sum += arr[i];
        ans = max(sum,ans);
        if(sum<0)
            sum = 0;
    }
    return max(ans,0ll);
}