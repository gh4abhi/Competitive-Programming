// Problem Link - https://www.hackerrank.com/contests/mission-4444-44-by-44/challenges/dirty-sequence

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long n; cin>>n;
    cout<<n<<" ";
    while(n!=1)
    {
        if(n&1)
        {
            cout<<3*n+1<<" ";
            n = 3*n+1;
        }
        else
        {
            cout<<n/2<<" ";
            n = n/2;
        }
    }
}
