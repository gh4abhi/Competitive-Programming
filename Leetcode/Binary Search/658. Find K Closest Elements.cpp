// Problem Link - https://leetcode.com/problems/find-k-closest-elements/

#define ll int

class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        ll start = 0, end = nums.size()-1;
        while(start<=end)
        {
            ll mid = start + (end-start)/2;
            if(nums[mid]>x)
                end = mid-1;
            else
                start = mid+1;
        }
        ll i=start-1;
        ll j =start;
        vector<ll> ans;
        while(i>=0 and j<nums.size() and k)
        {
            if(abs(x-nums[i])<=abs(x-nums[j]))
                ans.push_back(nums[i--]), k--;
            else
                ans.push_back(nums[j++]), k--;
        }
        while(k>0 and i>=0)
            ans.push_back(nums[i--]),k--;
        while(k>0 and j<nums.size())
            ans.push_back(nums[j++]),k--;
        sort(ans.begin(),ans.end());
        return ans;
    }
};