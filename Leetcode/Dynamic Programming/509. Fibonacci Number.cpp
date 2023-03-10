// Problem Link - https://leetcode.com/problems/fibonacci-number/

#define ll long long
class Solution {
public:
    ll fibonacciHelper(ll* ans, ll n)
{
    if(n<=1)
    {
        return n;
    }
    if(ans[n]!=-1)
    {
        return ans[n];
    }
    ll a = fibonacciHelper(ans,n-1);
    ll b = fibonacciHelper(ans,n-2);
    ans[n] = a+b;
    return ans[n];
}

ll fib(ll n)
{
    ll* ans = new ll[n+1];
    for(ll i=0;i<n+1;i++)
    {
        ans[i] = -1;
    }

    return fibonacciHelper(ans, n);
}
};
