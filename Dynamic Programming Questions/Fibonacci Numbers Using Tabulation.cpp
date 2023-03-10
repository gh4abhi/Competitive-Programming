// Fibonacci Numbers Using Tabulation

#include<bits/stdc++.h>
#define ll long long
#define Nil -1
using namespace std;
ll lookupTable[100];
void initialize(ll n)
{
    for(ll i=0;i<100;i++)
    {
        lookupTable[i] = Nil;
    }
}

ll fib(ll n)
{
    lookupTable[0] = 0;
    lookupTable[1] = 1;
    for(ll i=2;i<n;i++)
    {
        lookupTable[i] = lookupTable[i-1]+lookupTable[i-2];
    }
    
    return lookupTable[n];
}

int main()
{
    ll n;
    cin>>n;
    initialize(n);
    ll res = fib(n);
    for(ll i=0;i<n;i++)
    {
        cout<<lookupTable[i]<<" ";
    }
}
