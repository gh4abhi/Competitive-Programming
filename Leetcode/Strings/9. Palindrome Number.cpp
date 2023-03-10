// Problem Link - https://leetcode.com/problems/palindrome-number/

#define ll long long
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        ll x2 = x;
        ll sum = 0;
        ll fact = 1;
        while(x2)
        {
            sum = sum*fact + (x2%10);
            fact = 10;
            x2/=10;
        }
        return sum==x;
    }
};
