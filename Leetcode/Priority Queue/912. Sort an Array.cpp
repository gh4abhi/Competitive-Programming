// Problem Link - https://leetcode.com/problems/sort-an-array/

#define ll int

class Solution {
public:
    vector<ll> inplaceHeapSort(vector<ll> arr, ll n)
{
    for(ll i=0;i<n;i++)
    {
        ll childIndex = i;
        ll parentIndex = (i-1)/2;
        while(parentIndex>=0)
        {
            if(arr[parentIndex]>arr[childIndex])
            {
                swap(arr[parentIndex],arr[childIndex]);
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
            parentIndex = (childIndex-1)/2;
        }
    }
        vector<ll> ans;
    ll lastIndex = n-1;
    for(ll i=0;i<n;i++)
    {
        swap(arr[lastIndex],arr[0]);
        ans.push_back(arr[lastIndex]);
        ll parentIndex = 0;
        ll lChild = 2*parentIndex + 1;
        ll rChild = 2*parentIndex + 2;
        lastIndex--;
        while(lChild<lastIndex+1)
        {

            ll minIndex = parentIndex;
            if(arr[minIndex]>arr[lChild])
            {
                minIndex = lChild;
            }
            if(rChild<lastIndex + 1 and arr[minIndex]>arr[rChild])
            {
                minIndex = rChild;
            }
            if(minIndex==parentIndex)
            {
                break;
            }
            swap(arr[parentIndex],arr[minIndex]);
            parentIndex = minIndex;
            lChild = 2*parentIndex + 1;
            rChild = 2*parentIndex + 2;
        }
    }
        return ans;
}
    vector<int> sortArray(vector<int>& nums) {
        return inplaceHeapSort(nums,nums.size());
    }
};
