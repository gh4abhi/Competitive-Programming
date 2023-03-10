// Problem Link - https://www.codingninjas.com/codestudio/problems/1062582?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll long long

int compareVersions(string a, string b) 
{
    ll i=0,j=0,m=a.length(),n=b.length();
    while(i<m or j<n)
    {
        ll val1 = 0, val2 = 0;
        while(i<m and a[i]!='.')
            val1 = val1*10 + (a[i++]-'0');
        while(j<n and b[j]!='.')
            val2 = val2*10 + (b[j++]-'0');
        if(val1<val2)
            return -1;
        if(val2<val1)
            return 1;
        i++;
        j++;
    }
    return 0;
}