// Problem Link - https://leetcode.com/problems/power-of-three/

#define ll long long

class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n%3==0 and n)
            n/=3;
        if(n==1)
            return true;
        return false;
    }
};