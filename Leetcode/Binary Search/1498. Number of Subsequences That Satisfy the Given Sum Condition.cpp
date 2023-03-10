// Problem Link - https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

#define ll long long
#define MOD 1000000007

class Solution {
public:
    ll power(ll x, ll y, ll p)
{
    ll res = 1;
    while (y > 0) {
 
        if (y % 2 == 1)
            res = (res * x)%p;
        y = y >> 1;
 
        x = (x * x)%p;
    }
    return res % p;
}
    int numSubseq(vector<int>& nums, int target) {
        ll ans = 0;
        ll start = 0, end = nums.size()-1;
        sort(nums.begin(),nums.end());
        while(start<=end)
        {
            if(nums[start] + nums[end]<=target)
            {
                ans = (ans+power(2ll,end-start,MOD))%MOD;
                start++;
            }
            else end--;
        }
        return ans;
    }
};