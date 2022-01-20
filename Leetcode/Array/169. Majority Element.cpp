// Problem Link - https://leetcode.com/problems/majority-element/

#define ll int

class Solution {
public:
    
    ll findPotentialCandidate(vector<ll>& nums)
    {
        ll count = 1;
        ll value = nums[0];
        for(ll i=1;i<nums.size();i++)
        {
            if(nums[i]==value)
            {
                count++;
            }
            else
            {
                count--;
            }
            if(count==0)
            {
                value = nums[i];
                count = 1;
            }
        }
        return value;
    }
    
    int majorityElement(vector<int>& nums) {
        ll value = findPotentialCandidate(nums);
        ll count = 0;
        for(ll i=0;i<nums.size();i++)
        {
            if(nums[i]==value)
                count++;
        }
        if(count>nums.size()/2);
        {
            return value;
        }
    }
};
