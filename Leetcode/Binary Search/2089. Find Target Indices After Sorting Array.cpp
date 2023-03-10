// Problem Link - https://leetcode.com/problems/find-target-indices-after-sorting-array/

#define ll int

class Solution {
public:
    
    ll searchForFirst(vector<ll>& nums, ll target, ll check)
    {
        ll start =0, end = nums.size()-1;
        ll ans = -1;
        while(start<=end)
        {
            ll mid = start + (end-start)/2;
            if(nums[mid]>target)
                end = mid-1;
            else if(nums[mid]<target)
                start = mid + 1;
            else
            {
                ans = mid;
                if(check)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return ans;
    }
    
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<ll> ans;
        sort(nums.begin(),nums.end());
        ll beg = searchForFirst(nums,target,true);
        if(beg==-1)
            return ans;
        ll end = searchForFirst(nums,target,false);
        for(ll i=beg;i<=end;i++)
            ans.push_back(i);
        return ans;
    }
};