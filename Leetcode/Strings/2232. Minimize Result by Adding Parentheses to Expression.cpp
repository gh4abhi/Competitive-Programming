// Problem Link - https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/

#define ll int

class Solution {
public:
    string minimizeResult(string exp) {
        string pro1 = "";
        string pro2 = "";
        ll pos = -1;
        for(ll i=0;i<exp.length();i++)
            if(exp[i]=='+')
                pos = i;
        string a = "";
        ll ans = INT_MAX;
        ll ansi,ansj;
        for(ll i=0;i<pos;i++)
        {
            if(i>0)
                pro1+=(exp[i-1]);
            pro2 = "";
            for(ll j=exp.length()-1;j>pos;j--)
            {
                if(j<exp.length()-1)
                    pro2 = (exp[j+1]) + pro2;
                string pre = "", post = "";
                for(ll k = i;k<pos;k++)
                {
                    pre += exp[k];
                }
                for(ll k = j;k>pos;k--)
                {
                    post= exp[k] + post;
                }
                ll num1 = stoi(pre);
                ll num2 = stoi(post);
                ll one = 1;
                ll two = 1;
                if(pro1.length())
                    one = stoi(pro1);
                if(pro2.length())
                    two = stoi(pro2);
                ll temp = one*(num1 + num2)*two;
                if(temp<ans)
                {
                    ans = temp;
                    ansi = i;
                    ansj = j;
                }
            }
        }
        for(ll i=0;i<exp.length();i++)
        {
            if(i==ansi)
            {
                a += '(';
                a += exp[i];
            }
            else if(i==ansj)
            {
                a += exp[i];
                a += ')';
            }
            else
                a += exp[i];
        }
        return a;
    }
};