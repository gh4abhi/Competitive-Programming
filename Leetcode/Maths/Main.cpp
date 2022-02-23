// Problem Link - https://leetcode.com/problems/reverse-integer/

#define ll long long

class Solution {
public:
    int reverse(int x) {
        ll temp = x, flag=0;
        if(temp<0)
        {temp = -temp;
        flag=1;}
        ll rev = 0;
        ll pro = 1;
        while(temp)
        {
            if(rev*pro+temp%10>INT_MAX)
                return 0;
            rev=rev*pro+temp%10;
            temp/=10;
            pro = 10;
        }
        if(flag)
            rev=-rev;
        return rev;
    }
};