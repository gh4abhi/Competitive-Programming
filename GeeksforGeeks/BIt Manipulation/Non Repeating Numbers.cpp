// Problem Link - https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1#

#define ll int
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        vector<ll> ans;
        ll val = nums[0];
        for(ll i=1;i<nums.size();i++)
            val = val^nums[i];
        ll rightBit = val & ~(val-1);
        ll x= 0, y = 0;
        for(ll i=0;i<nums.size();i++)
        {
            if(nums[i]&rightBit)
                x = x^nums[i];
            else
                y = y^nums[i];
        }
        ans.push_back(min(x,y));
        ans.push_back(max(x,y));
        return ans;
    }
};