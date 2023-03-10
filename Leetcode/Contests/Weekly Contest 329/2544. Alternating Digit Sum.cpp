// Problem Link - https://leetcode.com/contest/weekly-contest-329/problems/alternating-digit-sum/

#define ll int

class Solution {
public:
    int alternateDigitSum(int n) {
        ll ans = 0;
        ll op = 0;
        while(n)
        {
            ll r = n%10;
            op = op*10 + r;
            n/=10;
        }
        ll flag = 1;
        while(op)
        {
            if(flag)
                ans += op%10;
            else
                ans += -(op%10);
            flag = !flag;
            op/=10;
        }
        return ans;
    }
};