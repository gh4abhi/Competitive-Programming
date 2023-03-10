// Problem Link - https://leetcode.com/problems/sort-colors/

#define ll int

class Solution {
public:
    void sortColors(vector<int>& a) {
        ll low = 0, mid =0 , high = a.size()-1;
        while(mid<=high)
        {
            if(a[mid]==0)
            {
                swap(a[low],a[mid]);
                low = low + 1;
                mid = mid + 1;
            }
            else if(a[mid]==1)
            {
                mid = mid +1;
            }
            else
            {
                swap(a[mid],a[high]);
                high = high-1;
            }
        }
    }
};
