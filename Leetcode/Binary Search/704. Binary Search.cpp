// Problem Link - https://leetcode.com/problems/binary-search/

#define ll int

class Solution {
public:
    int search(vector<int>& nums, int target) {
        ll i = 0, j = nums.size()-1;
        while(i<=j)
        {
            ll mid = i + (j-i)/2;
           
            if(nums[mid]>target)
                j = mid-1;
            else if(nums[mid]<target)
                i = mid+1;
            else 
                return mid;
        }
        return -1;
    }
};