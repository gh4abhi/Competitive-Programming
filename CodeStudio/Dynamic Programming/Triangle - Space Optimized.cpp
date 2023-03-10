// Problem Link - https://www.codingninjas.com/codestudio/problems/triangle_1229398?leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<ll> dp(1001,1e9);    
    dp[0] = triangle[0][0];
    for(ll i=1;i<n;i++)
    {
        vector<ll> temp(1001,0);
        for(ll j=0;j<triangle[i].size();j++)
        {
           if(j==0)
               temp[j] = dp[j] + triangle[i][j];
            else if(j!=triangle[i].size()-1)
            {
                temp[j] = min(dp[j-1],dp[j]);
                temp[j] += triangle[i][j];
             } 
            else
                temp[j] = dp[j-1] + triangle[i][j];
        }
        dp = temp;
    }
    ll ans = 1e9;
    for(ll i=0;i<triangle[n-1].size();i++)
        ans = min(ans,dp[i]);
    return ans;
}
// 2 
// 3 4
// 6 5 7
// 4 1 8 3