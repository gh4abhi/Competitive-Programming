// Problem Link - https://leetcode.com/contest/weekly-contest-316/problems/number-of-subarrays-with-gcd-equal-to-k/

#define ll int

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        ll n = nums.size();
        ll ans = 0;
        for(ll i=0;i<n;i++)
        {
            ll val = nums[i];
            for(ll j=i;j<n;j++)
            {
                val = __gcd(val,nums[j]);
                if(val==k)
                    ans++;
            }
        }
        return ans;
    }
};