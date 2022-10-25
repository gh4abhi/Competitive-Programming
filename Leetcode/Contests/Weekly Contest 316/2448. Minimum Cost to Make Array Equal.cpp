// Problem Link - https://leetcode.com/problems/minimum-cost-to-make-array-equal/

#define ll long long

class Solution {
public:
    
    ll check(vector<int>& nums, vector<int>& cost, ll x)
    {
        ll ans = 0;
        for(ll i=0;i<nums.size();i++)
            ans += abs(nums[i]-x*1ll)*cost[i];
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll end = LONG_MIN;
        ll start = LONG_MAX;
        for(auto i:nums)
            end = max(end,(ll)i), start = min(start,(ll)i);
        ll ans = LONG_MAX;
        while(start<=end)
        {
            ll mid = start + (end-start)/2ll;
            ll val1 = check(nums,cost,mid);
            ll val2 = check(nums,cost,mid+1);
            if(val1<val2)
                ans = min(ans,val1),end = mid-1;
            else
                ans = min(ans,val2), start = mid+1;
        }
        return ans;
    }
};