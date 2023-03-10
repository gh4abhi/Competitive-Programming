// Problem Link - https://www.codechef.com/START24B/problems/AVOIDCONTACT

#include<bits/stdc++.h>
#define ll int
#define pb push_back 
#define limit 100001

using namespace std;

void solve()
{
    ll x,y;
    cin>>x>>y;
    if(x==y)
    {
        cout<<(x+y-1);
        return;
    }
    if(y==0)
    {
        cout<<x;
        return;
    }

    if(y==1)
    {
        cout<<x+1;
        return;
    }
    
    if(y==2)
    {
        cout<<(x+2);
        return;
        
    }

    cout<<x+y;
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
