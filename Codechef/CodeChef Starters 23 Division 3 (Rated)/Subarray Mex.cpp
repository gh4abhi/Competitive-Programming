// Problem Link - https://www.codechef.com/START23C/problems/SUBMEX

#include<bits/stdc++.h>
#define ll int
#define pb push_back 

using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k,x;
        cin>>n>>k>>x;
        if(x>k)
        {
            cout<<-1<<endl;
            continue;
        }
       vector<ll> vect(k);
       ll a = x-1;
       for(ll i=0;i<x;i++)
       {
           vect[i] = a;
           a--;
       }
       for(ll i=x;i<k;i++)
       {
           vect[i] = x-1;
       }
       
       ll j = 0;
       
       for(ll i=0;i<n;i++)
       {
           cout<<vect[j]<<" ";
           j++;
           j=j%k;
       }
        cout<<endl;
    }
}
