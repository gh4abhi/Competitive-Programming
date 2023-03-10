// Problem Link - https://leetcode.com/problems/climbing-stairs/

#define ll long long
class Solution {
public:
    int climbStairs(int n) {
        ll* arr = new ll[max(n+1,3)];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        ll pro = 2;
        for(ll i=3;i<n+1;i++)
        {
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[n];
    }
};
