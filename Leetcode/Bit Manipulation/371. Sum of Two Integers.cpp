// Problem Link - https://leetcode.com/problems/sum-of-two-integers/

#define ll int

class Solution {
public:
    int getSum(int a, int b) {
        while(b)
        {
            ll temp = (unsigned)(a&b)<<1;
            a = a^b;
            b = temp;
        }
        return a;
    }
};