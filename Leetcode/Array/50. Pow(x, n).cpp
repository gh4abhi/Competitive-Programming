// Problem Link - https://leetcode.com/problems/powx-n/

#define ll long long

class Solution {
public:
    double myPow(double x, int n) {
        ll nn = n;
        if(nn<0)
            nn*=(-1);
        double ans = 1.0;
        while(nn)
        {
            if(nn&1)
                ans *= x, nn-=1;
            else 
                x*=x, nn/=2;
        }
        if(n<0)
            return 1.0/ans;
        return ans;
    }
};