// Problem Link - https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<ll> temp;
    temp.push_back(arr[0]);
    for(ll i=1;i<n;i++)
    {
        if(arr[i]>temp.back())
            temp.push_back(arr[i]);
        else
        {
            ll ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}
