// Problem Link - https://www.codechef.com/problems/SUBARRAYXOR

#include<bits/stdc++.h>
#define ll int
#define pb push_back 
#define limit 100001

using namespace std;

vector<ll> arr(limit);

int main()
{
    
    arr[1] = 1;
    ll p = 2;
    ll index = 2;
    while(index<limit)
    {
        arr[index] = p;
        ll ind = index;
        index++;
        for(ll j = 1;j<ind and index<limit;j++)
        {
            arr[index++] = arr[j];
        }
        p=p*2;
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
