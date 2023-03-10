// Problem Link - https://www.codingninjas.com/codestudio/problems/975268?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

ll median(ll val, priority_queue<ll> &maxHeap, priority_queue<ll,vector<ll>,greater<ll>> &minHeap)
{
    ll l = maxHeap.size();
    ll r = minHeap.size();
    if(l==0)
        maxHeap.push(val);
    else if(l==r)
    {
        if(val<minHeap.top())
            maxHeap.push(val);
        else
        {
            ll temp = minHeap.top();
            minHeap.pop();
            minHeap.push(val);
            maxHeap.push(temp);
        }
    }
    else
    {
        if(r==0)
        {
            if(val>maxHeap.top())
                minHeap.push(val);
            else
            {
                ll temp = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(val);
                minHeap.push(temp);
            }
        }
        else
        {
            if(val>=minHeap.top())
                minHeap.push(val);
            else
            {
                if(val<maxHeap.top())
                {
                    ll temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(val);
                    minHeap.push(temp);
                }
                else
                    minHeap.push(val);
            }
        }
    }
    l = maxHeap.size();
    r = minHeap.size();
    if((l+r)&1)
        return maxHeap.top();
    return (minHeap.top()+maxHeap.top())/2;
}

vector<int> findMedian(vector<int> &arr, int n){
    priority_queue<ll> maxHeap;
    priority_queue<ll,vector<ll>,greater<ll>> minHeap;
    vector<ll> ans;
    for(auto i:arr)
        ans.push_back(median(i,maxHeap,minHeap));
    return ans;
}
