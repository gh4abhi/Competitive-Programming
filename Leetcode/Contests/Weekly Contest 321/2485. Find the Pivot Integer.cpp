// Problem Link - https://leetcode.com/contest/weekly-contest-321/problems/find-the-pivot-integer/

#define ll long long

class Solution {
public:
    int pivotInteger(int n) {
        for(ll i=1;i<=n;i++)
        {
            ll op = (i*(i+1))/2;
            ll ok = (n*(n+1))/2 - (i*(i-1))/2;
            if(op==ok)
                return i;
        }
        return -1;
    }
};