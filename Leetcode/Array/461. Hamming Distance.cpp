// Problem Link - https://leetcode.com/problems/hamming-distance/

#define ll int

class Solution {
public:
    int hammingDistance(int x, int y) {
        ll m = x^y;
        ll count = 0;
        while(m)
        {
         count+= m&1;
            m>>=1;
        }
        return count;
    }
};
