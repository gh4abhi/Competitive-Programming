// Problem Link - https://www.codingninjas.com/codestudio/problems/893405?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int
int maximumProfit(vector<int> &prices){
    ll ans = 0;
    ll mini = prices[0];
    for(auto i:prices)
    {
        ans = max(ans,i-mini);
        mini = min(mini,i);
    }
    return ans;
}