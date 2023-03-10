// Problem Link - https://www.codingninjas.com/codestudio/problems/630519?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll long long
long getTrappedWater(long *arr, int n){
    ll start = 0, end = n-1;
    ll lmaxi = 0, rmaxi = 0;
    ll ans = 0;
    while(start<=end)
    {
        if(arr[start]<=arr[end])
        {
            if(arr[start]>=lmaxi)
                lmaxi = arr[start];
            else
                ans += lmaxi - arr[start];
            start++;
        }
        else
        {
            if(arr[end]>=rmaxi)
                rmaxi = arr[end];
            else
                ans += rmaxi - arr[end];
            end--;
        }
    }
    return ans;
}