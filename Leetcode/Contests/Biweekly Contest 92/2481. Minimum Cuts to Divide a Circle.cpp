// Problem Link - https://leetcode.com/contest/biweekly-contest-92/problems/minimum-cuts-to-divide-a-circle/

#define ll int

class Solution {
public:
    int numberOfCuts(int n) {
        if(n==1)
            return 0;
        if(n&1)
            return n;
        return n/2;
    }
};