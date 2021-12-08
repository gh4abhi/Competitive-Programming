// Problem Link - https://leetcode.com/problems/next-permutation/

#define ll int

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        ll n = nums.size();
        ll ind1=-1, ind2=-1;
        for(ll i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                ind1 = i;
                break;
            }
        }
        if(ind1 == -1)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
        for(ll i=n-1;i>ind1;i--)
        {
            if(nums[i]>nums[ind1])
            {
                ind2 = i;
                break;
            }
        }
        
        swap(nums[ind1], nums[ind2]);
        
        reverse(nums.begin()+ind1+1,nums.end());
        }
    }
};
