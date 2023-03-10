// Problem Link - https://www.codechef.com/START24B/problems/ORANDCON

#include<bits/stdc++.h>
#define ll int
#define pb push_back 
#define limit 100001

using namespace std;

bool isPwerOf2(ll x)
{
    return x && (!(x&(x-1)));
}

void solve()
{
    ll n;
    cin>>n;
    if(n==1)
    {
        cout<<11<<" "<<5<<" "<<1;
        return;
    }
    if(isPwerOf2(n))
    {
        cout<<n<<" "<<n+1<<" "<<n+2;
        return;
    }
    ll t = n;
    ll count = 0;
    ll arr1[32], arr2[32];
    
    for(ll i=0;i<32;i++)
    {
        ll r = n%2;
        if(r==1)
        count++;
        if(count==1 and r==1)
        {
            arr1[i] = 0;
        }
        else
        {
            arr1[i] = r;
        }
        if(count==2 and r==1)
        {
            arr2[i] = 0;
        }
        else
        {
            arr2[i] = r;
        }
        n = n/2;
    }
    
    ll a = 0;
    ll p = 1;
    for(ll i=0;i<32;i++)
    {
        a+= (arr1[i]*p);
        p*=2;
    }
    ll b = 0;
    p = 1;
    for(ll i=0;i<32;i++)
    {
        b+= (arr2[i]*p);
        p*=2;
    }
    
    cout<<a<<" "<<b<<" "<<t;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    
}
