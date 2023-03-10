// Problem Link - https://leetcode.com/problems/strictly-palindromic-number/

#define ll long long

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for(ll i=2;i<n-1;i++)
        {
            ll op = n;
            string str = "";
            while(op)
            {
                str += to_string(op%i);
                op/=i;
            }
            string ok = str;
            reverse(ok.begin(),ok.end());
            if(ok!=str)
                return false;
        }
        return true;
    }
};