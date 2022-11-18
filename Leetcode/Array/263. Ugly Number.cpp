// Problem Link - https://leetcode.com/problems/ugly-number/

#define ll long long
class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)
            return false;
        for(auto i:{2,3,5})
            while(n%i==0)
                n/=i;
        return n==1;
    }
};