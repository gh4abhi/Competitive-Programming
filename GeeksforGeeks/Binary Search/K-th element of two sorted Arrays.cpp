// Problem Link - https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

#define ll int

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(m<n)
            return kthElement(arr2,arr1,m,n,k);
        ll start = max(0,k-m);
        ll end = min(k,n);
        while(start<=end)
        {
            ll cut1 = (start) + (end-start)/2;
            ll cut2 = k - cut1;
            ll l1 = cut1==0?-1e9:arr1[cut1-1];
            ll r1 = cut1==n?1e9:arr1[cut1];
            ll l2 = cut2==0?-1e9:arr2[cut2-1];
            ll r2 = cut2==m?1e9:arr2[cut2];
            if(max(l1,l2)<=min(r1,r2))
                return max(l1,l2);
            if(l1>r2)
                end = cut1-1;
            else
                start = cut1+1;
        }
        return 0;
    }
};