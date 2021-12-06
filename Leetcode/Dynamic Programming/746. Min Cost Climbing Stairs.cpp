// Problem Link - https://leetcode.com/problems/min-cost-climbing-stairs/

#define ll int

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        ll n = cost.size();
        ll dp[n+1];
        for(ll i=0;i<=n;i++)
        {
            dp[i]=0;
        }
        for(ll i=n-1;i>=0;i--)
        {
            if(i==n-1)
            dp[i] = cost[i] + dp[i+1];
            else
            dp[i] = cost[i] + min(dp[i+1],dp[i+2]);    
        }
        return min(dp[0],dp[1]);
    }
};
