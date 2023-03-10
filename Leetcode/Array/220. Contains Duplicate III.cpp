// Problem Link - https://leetcode.com/problems/contains-duplicate-iii/

#define ll long long

class Solution {
public:
    ll min(ll a,ll b)
    {
        if(a<b)
            return a;
        return b;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size()==1 or k==0)
            return false;
        ll sz = min(k,nums.size()-1);
        map<ll,ll> window;
        for(ll i=0;i<=sz;i++)
            window[nums[i]]++;
        for(ll i=0;i<nums.size();i++)
        {
            window[nums[i]] -= 1;
            if(window[nums[i]]==0)
                window.erase(nums[i]);
            ll val = nums[i];
            ll op = t;
            val+=op;
            auto it = window.lower_bound(val);
            if(it!=window.end())
                if(abs(nums[i]-(it->first))<=t)
                    return true;
            val-=2*op;
            it = window.lower_bound(val);
            if(it!=window.end())
                if(abs(nums[i]-(it->first))<=t)
                    return true;
            if(i+k+1<nums.size())
                window[nums[i+k+1]]++;            
        }
        return false;
    }
};