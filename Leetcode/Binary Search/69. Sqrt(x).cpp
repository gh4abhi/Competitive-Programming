// Problem Link - https://leetcode.com/problems/sqrtx/

#define ll long long

class Solution {
public:
    int mySqrt(int x) {
        ll start = 1, end = x;
        while(start<=end)
        {
            ll mid = (start) + (end-start)/2;
            if(mid*mid>x)
                end = mid - 1;
            else if(mid*mid<x)
                start = mid + 1;
            else
                return mid;
        }
        return end;
    }
};