// Problem Link - https://leetcode.com/problems/merge-sorted-array/

#define ll int

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    ll i=0,j=0;
        if(m==0)
        {
            nums1 = nums2;
            return;
        }
        if(n==0)
        {
            return;
        }
        vector<ll> ans;
        while(i<m and j<n)
        {
            if(nums1[i]==nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                ans.push_back(nums2[j]);
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n)
        {
            ans.push_back(nums2[j]);
            j++;
        }
        nums1 =  ans;
    }
};
