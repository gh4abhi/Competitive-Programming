// Problem Link - https://leetcode.com/problems/contains-duplicate-ii/

#define ll long long

class Solution {
public:
    ll min(ll a,ll b)
    {
        if(a<b)
            return a;
        return b;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<ll,ll> m;
        ll sz = min(k,nums.size()-1);
        for(ll i=0;i<=sz;i++)
            m[nums[i]]++;
        for(ll i=0;i<nums.size();i++)
        {
            m[nums[i]]--;
            if(m[nums[i]]==0)
                m.erase(nums[i]);
            if(m.count(nums[i]))
                return true;
            if(i+k+1<nums.size())
                m[nums[i+k+1]]++;
        }
        return false;
    }
};