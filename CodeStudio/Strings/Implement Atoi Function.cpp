// Problem Link - https://www.codingninjas.com/codestudio/problems/981270?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

int atoi(string s) {
    string str="";
        ll i=0;
        while(s[i]==' ')
            i++;
        ll flag = 0;
        ll count = 0;
        if(s[i]=='+')
            i++;
        else if(s[i]=='-')
            i++,flag = 1;
        for(ll j=i;j<s.length();j++)
        {
            if(s[j]==' ')
                break;
            if(s[j]=='0' and str.length()==0)
                continue;
            else if(s[j]>='0' and s[j]<='9')
                str+=s[j];
        }
        ll ans = 0;
        ll pro = 1;
        for(ll j=str.length()-1;j>=0;j--)
        {
            if(ans>INT_MAX or pro>INT_MAX)
            {
                ans = INT_MAX+100ll;
                break;
            }
            ans += (str[j]-'0')*pro, pro*=10;
        }
        if(flag)
            ans = -ans;
        if(ans<INT_MIN)
            ans = INT_MIN;
        if(ans>INT_MAX)
            ans = INT_MAX;
        return ans;
}