// Problem Link - https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

#define ll int

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        ll start = -1;
        ll end = -1;
        ll mini = INT_MAX, maxi = INT_MIN;
        for(ll i=1;i<nums.size();i++)
            if(nums[i-1]>nums[i])
            {
                start = i-1;
                maxi = nums[i-1];
                mini = nums[i];
                break;
            }

        for(ll i=nums.size()-2;i>=0;i--)
            if(nums[i]>nums[i+1])
            {
                mini = min(nums[i+1],mini);
                maxi = max(nums[i],maxi);
                end = i+1;
                break;
            }
        
        if(start!=-1)
        for(ll i=start;i<=end;i++)
            mini = min(nums[i],mini), maxi = max(nums[i],maxi);
        
        for(ll i=0;i<nums.size();i++)
            if(mini<nums[i])
            {
                start = min(start,i);
                break;
            }

        for(ll i=nums.size()-1;i>=0;i--)
            if(maxi>nums[i])
            {
                end = max(end,i);
                break;
            }

        if(start==-1)
            return 0;
        return (end-start+1);
    }
};