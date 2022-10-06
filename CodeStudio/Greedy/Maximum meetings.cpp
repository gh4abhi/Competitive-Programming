// Problem Link - https://www.codingninjas.com/codestudio/problems/1062658?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

struct meet
{
    ll start;
    ll end;
    ll ind;
};

bool cmp(struct meet &a, struct meet &b)
{
    if(a.end!=b.end)
        return a.end<b.end;
    return a.ind<b.ind;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    ll n = start.size();
    vector<ll> ans;
    struct meet arr[n];
    for(ll i=0;i<n;i++)
        arr[i].start = start[i], arr[i].end = end[i], arr[i].ind = i;
    sort(arr,arr+n,cmp);
    ll mEnd = INT_MIN;
    for(ll i=0;i<n;i++)
        if(arr[i].start>mEnd)
            mEnd = arr[i].end, ans.push_back(arr[i].ind+1);
    return ans;
}