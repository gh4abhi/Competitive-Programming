// Problem Link - https://leetcode.com/contest/weekly-contest-318/problems/maximum-sum-of-distinct-subarrays-with-length-k/

#define ll long long

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<ll> pre(n,0);
        pre[0] = nums[0];
        for(ll i=1;i<n;i++)
            pre[i] += pre[i-1] + nums[i];
        unordered_map<ll,ll> m;
        ll ans = 0;
        for(ll i=0;i<n;i++)
        {
            if(i<k-1)
                m[nums[i]]++;
            else
            {
                m[nums[i]]++;
                ll op = 0;
                if(i-k>=0)
                {
                    op = pre[i-k];
                    m[nums[i-k]]--;
                    if(m[nums[i-k]]==0)
                        m.erase(nums[i-k]);
                }
                op = pre[i]-op;
                if(m.size()==k)
                    ans = max(ans,op);
            }
        }
        return ans;
    }
};