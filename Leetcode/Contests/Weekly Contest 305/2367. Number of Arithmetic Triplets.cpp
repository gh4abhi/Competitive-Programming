// Problem Link - https://leetcode.com/contest/weekly-contest-305/problems/number-of-arithmetic-triplets/

#define ll int

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        ll ans = 0;
        ll n = nums.size();
        for(ll i=0;i<nums.size();i++)
        {
            for(ll j=i+1;j<n;j++)
            {
                for(ll k=j+1;k<n;k++)
                {
                    if(nums[j]-nums[i]==nums[k]-nums[j] and nums[j]-nums[i]==diff)
                        ans++;
                }
            }
        }
        return ans;
    }
};  