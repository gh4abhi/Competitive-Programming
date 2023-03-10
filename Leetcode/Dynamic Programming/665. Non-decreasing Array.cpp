// Problem Link - https://leetcode.com/problems/non-decreasing-array/

#define ll int

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        ll ans = 1;
        vector<ll> vect;
        vect.push_back(nums[0]);
        for(ll i=1;i<nums.size();i++)
        {
            if(vect.back()<=nums[i])
                vect.push_back(nums[i]);
            else
            {
                ll ind = upper_bound(vect.begin(),vect.end(),nums[i]) - vect.begin();
                vect[ind] = nums[i];
            }
        }
        return vect.size()>=nums.size()-1;
    }
};