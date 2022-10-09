// Problem Link - https://www.codingninjas.com/codestudio/problems/mining-diamonds_4244494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

int maxCoins(vector<int>& nums)
{
        ll n = nums.size();
        vector<vector<ll>> dp(n+2,vector<ll>(n+2,0));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        for(ll i=n;i>=1;i--)
        {
            for(ll j=1;j<=n;j++)
            {
                for(ll ind = i;ind<=j;ind++)
                {
                    dp[i][j] = max(dp[i][j],nums[i-1]*nums[j+1]*nums[ind] + dp[ind+1][j] + dp[i][ind-1]);
                }
            }
        }
        return dp[1][n];
}