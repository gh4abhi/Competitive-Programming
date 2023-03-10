// Problem Link - https://leetcode.com/problems/single-element-in-a-sorted-array/

#define ll int

class Solution {
public:
    int singleNonDuplicate(vector<int>& vect) {
        if(vect.size()==1)
            return vect[0];
        ll start = 0, end = vect.size()-2;
        while(start<=end)
        {
            ll mid = start + (end-start)/2;
            if(vect[mid]==vect[mid+1])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return vect[start];
    }
};