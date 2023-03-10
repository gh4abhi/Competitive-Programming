// Problem Link - https://www.codingninjas.com/codestudio/problems/873378?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

ll numSmall(vector<int> vect, ll x)
{
    ll start = 0, end = vect.size()-1;
    while(start<=end)
    {
        ll mid = start + (end - start)/2;
        if(vect[mid]<=x)
            start = mid + 1;
        else
            end = mid-1;
    }
    return start;
}

int getMedian(vector<vector<int>> &matrix)
{
    ll start = 1, end = 1e6;
    ll n = matrix.size();
    ll m = matrix[0].size();
    while(start<=end)
    {
        ll mid = start + (end-start)/2;
        ll count = 0;
        for(auto i:matrix)
            count += numSmall(i,mid);
        if(count<=(n*m)/2)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start;
}