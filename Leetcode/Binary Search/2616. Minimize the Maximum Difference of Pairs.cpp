// Problem Link - https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

#define ll int

class Solution {
public:

    bool isPossible(vector<ll> &nums, ll x, ll p)
    {
        ll count = 0;
        for(ll i=0;i<nums.size();)
        {
            if(i+1<nums.size() and nums[i+1]-nums[i]<=x)
                count+=1, i+=2;
            else
                i+=1;
        }
        return count>=p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        ll start=0, end = 1e9;
        sort(nums.begin(),nums.end());
        while(start<=end)
        {
            ll mid = start + (end-start)/2;
            if(isPossible(nums,mid,p))
                end = mid-1;
            else
                start = mid+1;
        }
        return start;
    }
};