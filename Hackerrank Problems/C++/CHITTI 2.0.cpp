// Problem Link - https://www.hackerrank.com/contests/mission-4444-44-by-44/challenges/chitti-2-0

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll int
using namespace std;


int main() {
    int n; cin>>n;
    string s; cin>>s;
    ll l=0,r=0;
    for(auto i:s)
    {
        if(i=='L')
        {
            l++;
        }
        else
        {
            r++;
        }
        }
    cout<<(l+r+1);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
