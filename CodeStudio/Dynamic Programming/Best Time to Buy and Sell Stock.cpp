// Problem Link - https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int
int maximumProfit(vector<int> &prices){
    ll ans = 0;
    ll mini = prices[0];
    for(ll i=0;i<prices.size();i++)
        mini = min(mini,prices[i]), ans = max(ans,prices[i]-mini);
    return ans;
}