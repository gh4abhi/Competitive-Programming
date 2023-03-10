// Problem Link - https://www.codingninjas.com/codestudio/problems/1082146?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll long long

int modularExponentiation(int x, int n, int m) {
    ll ans = 1;
    while(n)
    {
        if(n&1)
            ans  = (1ll*ans*x)%m,n-=1;
        else
            x = (1ll*x*x)%m, n/=2;
    }
    return ans%m;
}