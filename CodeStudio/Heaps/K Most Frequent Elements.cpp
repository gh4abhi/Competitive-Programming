// Problem Link - https://www.codingninjas.com/codestudio/problems/k-most-frequent-elements_3167808?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<ll,ll> m;
    for(auto i:arr)
        m[i]++;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    for(auto i:m)
        pq.push({-i.second,i.first});
    vector<ll> ans;
    while(k--)
        ans.push_back(pq.top().second), pq.pop();
    sort(ans.begin(),ans.end());
    return ans;
}