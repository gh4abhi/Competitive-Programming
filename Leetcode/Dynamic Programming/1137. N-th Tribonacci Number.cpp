// Problem Link - https://leetcode.com/problems/n-th-tribonacci-number/

#define ll int

class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 1;
        vector<ll> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(ll i=3;i<=n;i++)
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        return dp[n];
    }
};