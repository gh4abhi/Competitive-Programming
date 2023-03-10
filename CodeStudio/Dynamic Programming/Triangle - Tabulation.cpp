// Problem Link - https://www.codingninjas.com/codestudio/problems/triangle_1229398?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int minimumPathSum(vector<vector<int>>& triangle, int n){
    ll dp[1001][1001];    
    dp[0][0] = triangle[0][0];
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<triangle[i].size();j++)
        {
            dp[i][j] = 1e9;
            if(j>0)
            dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
            if(j!=triangle[i].size()-1)
            dp[i][j] = min(dp[i][j],dp[i-1][j]);
            dp[i][j] += triangle[i][j];
        }
    }
    ll ans = 1e9;
    for(ll i=0;i<triangle[n-1].size();i++)
        ans = min(ans,dp[n-1][i]);
    return ans;
}
// 2 
// 3 4
// 6 5 7
// 4 1 8 3