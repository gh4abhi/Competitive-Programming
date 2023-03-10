// Problem Link - https://leetcode.com/problems/rotate-array/

#define ll int

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        ll n = nums.size();
        k = k%n;
        if(k<0)
            k+=n;
        ll l = n-k, r = n-1;
        while(l<r)
        {
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
        l = 0;
        r = n-k-1;
        while(l<r)
        {
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
        
        l = 0;
        r = n-1;
        while(l<r)
        {
            swap(nums[l],nums[r]);
            l++;
            r--;
         }
    }
};
