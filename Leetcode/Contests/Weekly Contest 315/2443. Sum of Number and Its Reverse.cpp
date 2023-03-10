// Problem Link - https://leetcode.com/contest/weekly-contest-315/problems/sum-of-number-and-its-reverse/

#define ll long long

class Solution {
public:
    
    ll reverse(ll op)
    {
        ll ok = 0;
        while(op)
        {
            ok = ok*10+op%10;
            op/=10;
        }
        return ok;
    }
    
    bool sumOfNumberAndReverse(int num) {
        for(ll i=0;i<=num;i++)
        {
            ll a = i;
            ll b = reverse(i);
            if(a+b==num)
                return true;
        }
        return false;
    }
};