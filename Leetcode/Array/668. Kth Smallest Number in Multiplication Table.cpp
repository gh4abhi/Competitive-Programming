// Problem Link - https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

#define ll int

class Solution {
public:
    ll findKthNumberHelper(ll n, ll m, ll mid)
{
    ll count = 0;
    for(ll i=1;i<=m;i++)
        count += min(mid/i,n);
    return count;
}
int findKthNumber(int m, int n, int k) {
    ll high = (m*n);
    ll low = 1;
    ll mid = (high+low)/2;
    ll x  = 10;
    while(low<high)
    {
        ll count = findKthNumberHelper(n,m,mid);
        if(count>=k)
        {
            high = mid;
        }
        else
        {
            low = mid+1;
        }
        mid = (high+low)/2;
    }
    return high;
}

};
