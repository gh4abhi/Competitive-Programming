// Problem Link - https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/

#define ll int

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length()&1)
            return false;
        ll op = 0;
        ll ok = 0;
        for(ll i=0;i<s.length();i++)
        {
            if(locked[i]=='0')
                op++;
            else
            {
                if(s[i]=='(')
                    ok++;
                else
                    ok--;
                if(ok<0)
                {
                    ok = 0;
                    if(op==0)
                        return false;
                    else
                        op--;
                }
            }
        }
        op = 0;
        ok = 0;
        for(ll i=s.length()-1;i>=0;i--)
        {
            if(locked[i]=='0')
                op++;
            else
            {
                if(s[i]=='(')
                    ok--;
                else
                    ok++;
                if(ok<0)
                {
                    ok = 0;
                    if(op==0)
                        return false;
                    else
                        op--;
                }
            }
        }
        return true;
    }
};