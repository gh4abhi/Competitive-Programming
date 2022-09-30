// Problem Link - https://leetcode.com/problems/multiply-strings/

#define ll int

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" or num2=="0" or num1.length()==0 or num2.length()==0)
            return "0";
        if(num1=="1")
            return num2;
        if(num2=="1")
            return num1;
        ll m = num1.length();
        ll n = num2.length();
        string ans = string(m+n,'0');
        for(ll i=m-1;i>=0;i--)
        {
            for(ll j=n-1;j>=0;j--)
            {
                ll op = (num1[i]-'0')*(num2[j]-'0');
                op += (ans[i+j+1]-'0');
                ans[i+j+1] = ('0' + (op%10));
                ll ok = (ans[i+j]-'0');
                ok+=op/10;
                ans[i+j] = ('0'+ok);
            }
        }
        ll i =0;
        while(ans[i]=='0')
            i++;
        return ans.substr(i,ans.length());
    }
};