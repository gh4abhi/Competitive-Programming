// Problem Link - https://leetcode.com/problems/number-complement/

#define ll int
class Solution {
public:
    int findComplement(int num) {
        ll op = 0;
        ll ans = 0;
        while(num)
        {
            ll r = num%2;
            num/=2;
            ans = pow(2,op)*(!r) + ans;
            op+=1;
        }
        return ans;
    }
};