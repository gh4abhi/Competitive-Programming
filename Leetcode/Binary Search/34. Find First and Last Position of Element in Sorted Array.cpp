// Problem Link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

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
            {
                end = mid-1;
            }
            else if(nums[mid]<target)
            {
                start = mid + 1;
            }
            else
            {
                ans = mid;
                if(check)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<ll> vect = {-1,-1};
        vect[0] = searchForFirst(nums, target, true);
        if(vect[0]!=-1)
            vect[1] =  searchForFirst(nums, target, false);
        return vect;
    }
};