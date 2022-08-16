// Problem Link - https://www.codingninjas.com/codestudio/problems/ayush-gives-ninjatest_1097574?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long
bool isPossible(vector<int> time, ll x, ll n)
{
    ll days = 1, curTime = 0;
    for(auto i:time)
    {
        if(curTime+i<=x)
            curTime += i;
        else
        {
            if(i>x)
                return false;
            curTime = i;
            days++;
        }
    }
    return days<=n;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{   
    ll end = 0;
    ll start = 1e18;
    if(time.size()<n)
        return -1;
    for(auto i:time)
        end += i, start = min(start,(ll)i);
    while(start<=end)
    {
        ll mid = start + (end-start)/2;
        if(isPossible(time,mid,n))
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start;
}