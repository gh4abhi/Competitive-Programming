// Problem Link - https://www.codingninjas.com/codestudio/problems/unique-subsets_3625236?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

void DFS(ll ind, vector<vector<ll>> &ans, vector<ll> &ds, vector<ll> &arr)
{
    ans.push_back(ds);
    for(ll i = ind;i<arr.size();i++)
    {
        if(i>ind and arr[i]==arr[i-1])
            continue;
        ds.push_back(arr[i]);
        DFS(i+1,ans,ds,arr);
        ds.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<ll>> ans;
    vector<ll> ds;
    sort(arr.begin(),arr.end());
    DFS(0,ans,ds,arr);
    return ans;
}