// Problem Link - https://leetcode.com/contest/weekly-contest-317/problems/minimum-addition-to-make-integer-beautiful/

#define ll long long

class Solution {
public:
    
    long long makeIntegerBeautiful(long long n, int target) {
        ll sum = 0;
        ll op = n;
        while(op)
            sum += op%10, op/=10;
        ll ok = 0;
        ll pro = 1;
        ll carry = 0;
        op = n;
        while(sum>target)
        {
            ll val = op%10+carry;
            ll r = op%10+carry;
            val = (10-val);
            sum-=(r-1);
            carry = 1;
            ok = pro*val + ok;
            pro*=10;
            op/=10;
        }
        return ok;
    }
};