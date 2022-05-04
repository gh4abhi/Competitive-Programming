// Problem Link - https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/

#define ll long long
#define MOD 1000000007

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<ll> freq(nums.size(),0);
        for(auto i:requests)
        {
          freq[i[0]] +=1;
          if(i[1]+1<nums.size())
              freq[i[1]+1] -=1;
        }
        for(ll i=1;i<nums.size();i++)
            freq[i] += freq[i-1];
        sort(freq.begin(),freq.end(),greater<ll>());
        sort(nums.begin(),nums.end(),greater<ll>());
        ll ans = 0;
        for(ll i=0;i<nums.size();i++)
            ans = (ans%MOD + ((nums[i])%MOD*(freq[i])%MOD)%MOD)%MOD;
        return (int)ans;
    }
};