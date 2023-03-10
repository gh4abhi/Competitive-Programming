// Problem Link - https://leetcode.com/contest/biweekly-contest-99/problems/count-total-number-of-colored-cells/

#define ll long long

class Solution {
public:
    long long coloredCells(int n) {
        if(n&1)
        {
            ll op = 0;
            for(ll i=1;i<n;i+=2)
                op += i;
            op = op*4ll;
            op += (2*n*1ll) + (2ll*(n-2ll));
            op += (n-2ll)*(n-2ll);
            return op;
        }
        ll op = 0;
        for(ll i=1;i<n;i+=2)
            op += i;
        op = op*4ll;
        op += (n-1ll)*(n-1ll);
        return op;
    }
};