// Problem Link - https://leetcode.com/problems/largest-sum-of-averages/

#define ll int

class Solution {
public:
    
    double maxi(ll i, ll j, vector<ll> &nums, ll k, vector<ll> &pre, ll n, vector<vector<vector<double>>> &dp)
    {
        if(k==1)
            return (pre[n]-pre[j]*1.0)/((n-j)*1.0);
        if(i==nums.size()+1)
            return INT_MIN;
        double ans = 0;
        if(dp[i][j][k]!=-1.0)
            return dp[i][j][k];
        for(ll ind=i;ind<nums.size();ind++)
            ans = max(ans,((pre[ind]-pre[j])*1.0)/((ind-j)*1.0) + maxi(ind+1,ind,nums,k-1,pre,n,dp));
        return dp[i][j][k] = ans;
    }
    
    double largestSumOfAverages(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        vector<ll> pre(n+1,0);
        for(ll i=0;i<nums.size();i++)
            pre[i+1] = pre[i] + nums[i];
        return maxi(1,0,nums,k,pre,n,dp);
    }
};