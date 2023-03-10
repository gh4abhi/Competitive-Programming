// Problem Link - https://practice.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1

#define ll long long
#define MOD 1000000007

class Solution{
    public:
    int Maximize(int a[],int n)
    {
        sort(a,a+n);
        ll ans = 0;
        for(ll i=0;i<n;i++)
            ans = (ans + (i*a[i]));
        return ans%MOD;
    }
};