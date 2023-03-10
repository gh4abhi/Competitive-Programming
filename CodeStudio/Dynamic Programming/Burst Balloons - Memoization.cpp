// Problem Link - https://www.codingninjas.com/codestudio/problems/mining-diamonds_4244494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

ll maxi(vector<ll> &nums, ll i, ll j, vector<vector<ll>> &dp)
    {
        if(i>j)
            return 0;
        ll op = INT_MIN;
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(ll ind = i;ind<=j;ind++)
            op = max(op,nums[i-1]*nums[j+1]*nums[ind] + maxi(nums,i,ind-1,dp) + maxi(nums,ind+1,j,dp));
        return dp[i][j] = op;
    }

int maxCoins(vector<int>& nums)
{
        ll n = nums.size();
        vector<vector<ll>> dp(n+2,vector<ll>(n+2,-1));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return maxi(nums,1,n,dp);
}