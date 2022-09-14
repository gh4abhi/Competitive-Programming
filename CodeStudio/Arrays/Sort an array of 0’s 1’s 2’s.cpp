// Problem Link - https://www.codingninjas.com/codestudio/problems/631055?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

void sort012(int *arr, int n)
{
   ll start = 0, mid = 0, end = n-1;
    while(mid<=end)
    {
        if(arr[mid]==0)
            swap(arr[mid],arr[start]), start += 1, mid += 1;
        else if(arr[mid]==1)
            mid += 1;
        else
            swap(arr[mid],arr[end]), end -= 1;
    }
}