// Problem Link - https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

#define ll long long
class Solution {
public:
    int numberOfSteps(int n) {
    ll* arr = new ll[max(n+1,4)];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    for(ll i=3; i<n+1;i++)
    {
        ll a = INT_MAX, b = INT_MAX;
        if(i%2==0)
        {
            a = arr[i/2];
        }
        else
        {
            b = arr[i-1];
        }
        arr[i] = 1+min(a,b);
    }
    return arr[n];
    }
};
