// Problem Link - https://www.codingninjas.com/codestudio/problems/893027?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

vector<int> majorityElementII(vector<int> &arr)
{
    ll a = -1, b = -1;
    ll count1 = 0, count2 = 0;
    for(auto i:arr)
    {
        if(a==i)
            count1++;
        else if(b==i)
            count2++;
        else if(count1==0)
            a = i, count1 = 1;
        else if(count2==0)
            b=i, count2 = 1;
        else
            count1-=1, count2-=1;
    }
    count1=0;
    count2=0;
    for(auto i:arr)
    {
        if(i==a)
            count1++;
        else if(i==b)
            count2++;
    }
    vector<ll> ans;
    if(count1>arr.size()/3)
        ans.push_back(a);
    if(count2>arr.size()/3)
        ans.push_back(b);
    return ans;
}   