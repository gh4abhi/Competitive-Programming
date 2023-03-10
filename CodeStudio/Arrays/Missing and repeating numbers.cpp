// Problem Link - https://www.codingninjas.com/codestudio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    ll repeat;
    for(ll i=0;i<n;i++)
    {
        if(arr[abs(arr[i])-1]<0)
            repeat = abs(arr[i]);
        else
            arr[abs(arr[i])-1] *= (-1);
    }
    for(ll i=0;i<n;i++)
        if(arr[i]>0)
            return {i+1,repeat};
    return {-1,repeat};
}
