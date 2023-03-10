// Problem Link - https://leetcode.com/problems/median-of-two-sorted-arrays/

#define ll long long

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size())
            return findMedianSortedArrays(nums2,nums1);
        ll n1 = nums1.size();
        ll n2 = nums2.size();
        ll start = 0, end = n1;
        while(start<=end)
        {
            ll cut1 = start + (end-start)/2;
            ll cut2 = (n1+n2+1)/2 - cut1;
            ll l1,r1,l2,r2;
            if(cut1==0)
                l1 = -1e9;
            else
                l1 = nums1[cut1-1];
            if(cut1==n1)
                r1 = 1e9;
            else
                r1 = nums1[cut1];
            if(cut2==0)
                l2 = -1e9;
            else
                l2 = nums2[cut2-1];
            if(cut2==n2)
                r2 = 1e9;
            else
                r2 = nums2[cut2];
            if(l1<=r2 and l2<=r1)
            {
                if((n1+n2)&1)
                    return max(l1,l2);
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            if(l1>r2)
                end = cut1 - 1;
            else
                start = cut1 + 1;
        }
        return -1.0;
    }
};