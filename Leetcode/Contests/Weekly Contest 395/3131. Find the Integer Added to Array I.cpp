// Problem Link - https://leetcode.com/problems/find-the-integer-added-to-array-i/

#define ll int

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        return nums2[0] - nums1[0];
    }
};