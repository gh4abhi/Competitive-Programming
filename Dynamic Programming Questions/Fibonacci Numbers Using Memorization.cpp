// Fibonacci Numbers Using Memorization

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
    if(lookupTable[n]==Nil)
    {
        if(n<=1)
        {
            lookupTable[n]=n;
        }
        else
        {
            lookupTable[n] = fib(n-1)+fib(n-2);
        }
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
