// Problem Link - https://leetcode.com/contest/weekly-contest-329/problems/minimum-cost-to-split-an-array/

#define ll int

class Solution {
public:
    ll mini(ll ind, vector<ll> &nums, ll &k, vector<ll> &dp, vector<vector<ll>> &op)
    {
        if(ind==nums.size())
            return 0;
        ll ans = INT_MAX;
        ll count = 0;
        if(dp[ind]!=-1)
            return dp[ind];
        for(ll i=ind;i<nums.size();i++)
        {
            if(op[i+1][i+1]-op[i+1][ind]==2)
                count+=2;
            else if(op[i+1][i+1]-op[i+1][ind]>2)
                count+=1;
            ans = min(ans,count+k+mini(i+1,nums,k,dp,op));
        }
        return dp[ind] = ans;
    }
    
    int minCost(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<vector<ll>> op(n+1,vector<ll>(n+1,0));
        for(ll i=0;i<n;i++)
        {
            ll count = 0;
            for(ll j=0;j<n;j++)
            {
                if(nums[i]==nums[j])
                    count++;
                op[i+1][j+1] = count;
            }
        }
        vector<ll> dp(nums.size()+1,-1);
        return mini(0,nums,k,dp,op);
    }
};