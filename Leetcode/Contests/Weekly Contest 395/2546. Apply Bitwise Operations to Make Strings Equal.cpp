// Problem Link - https://leetcode.com/problems/minimum-array-end/

#define ll long long

class Solution {
public:
    long long minEnd(int n, int x) {
        ll a = x;
        n-=1;
        while(n--)
            a = (a+1)|x;
        return a;
    }
};