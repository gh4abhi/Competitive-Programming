// Problem Link - https://www.hackerrank.com/contests/mission-4444-44-by-44/challenges/hello-string-1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#define ll int
using namespace std;


int main() {
    ll n;
    cin>>n;
    string str1,str2;
    cin>>str1>>str2;
    map<char,ll> m;
    for(auto i:str1)
    {
        m[i]++;
    }
    ll count = 0;
    for(auto i:str2)
    {
        if(m.count(i)>0 and m[i])
        {
            count++;
            m[i]--;
        }
    }
    if(count&1 or count==0)
    {
        cout<<"UNHAPPY";
    }
    else
    {
        cout<<"HAPPY";
    }
    return 0;
}

