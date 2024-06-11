// Problem Link - https://leetcode.com/problems/subarray-sums-divisible-by-k/description/?envType=daily-question&envId=2024-06-09

#define ll int

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<ll,ll> m;
        ll sum = 0;
        ll ans = 0;
        m[0] = 1;
        for(ll i=0;i<nums.size();i++)
        {
            sum += nums[i];
            ll op = 0;
            if(sum<0)
                while(sum<0)
                    op = (sum+k)%k, sum = op;
            else
                op = sum%k;
            if(m.count(op))
                ans += m[op];
            m[op]+=1;
        }
        return ans;
    }
};