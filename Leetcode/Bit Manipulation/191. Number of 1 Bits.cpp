// Problem Link - https://leetcode.com/problems/number-of-1-bits/

#define ll unsigned long long

class Solution {
public:
    int hammingWeight(uint32_t n) {
        ll count = 0;
        ll val = 1;
        for(ll i=0;i<32;i++)
        {
            if(n&val)
                count++;
           val = val<<1;
        }
        return (int)count;
    }
};