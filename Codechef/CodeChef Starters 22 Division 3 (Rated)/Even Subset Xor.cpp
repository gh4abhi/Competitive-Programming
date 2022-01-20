// Problem Link - https://www.codechef.com/START22C/problems/EVENXOR

#include <bits/stdc++.h>
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define empb emplace_back
#define mpr make_pair
#define sortit(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define issorted(v) is_sorted(v.begin(),v.end())
#define prt1(a) cout<<a<<" ";
#define prt2(a,b) cout<<a<<" "<<b<<" ";
#define prt3(a,b,c) cout<<a<<" "<<b<<" "<<c<<" ";
#define ll long long
#define vec  vector<ll>
#define pb push_back
#define pa vector<pair<ll,ll>>
#define fi first
#define se second
#define siz size()
#define full(a) a.begin(),a.end()
#define max_val INT_MIN
#define min_val INT_MAX;
#define MOD 1000000007


using namespace std;

void inOt()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
}

void its_Function(vector<ll> vect) {
    ll n;
    cin>>n;
if(n==1)
{
    cout<<3;
    return;
}
for(ll i=0;i<n;i++)
{
    cout<<vect[i]<<" ";
}
}

int main()
{

    BOOST;
#ifndef ONLINE_JUDGE
    inOt();
#endif
    cout<<fixed;
    vector<ll> vect;

    for(ll i=1;i<=1048576;i++)
    {
        ll count = 0;
        ll temp = i;
        for(ll j=0;j<32;j++)
        {
            ll r = (temp%2);
            if(r)
            count++;
            temp = temp/2;
        }
        if(count%2==0)
        {
            vect.pb(i);
        }
    }
    ll t;
    cin>>t;
    while(t--)
    {
        its_Function(vect);
        cout<<endl;
    }
//    its_Function();

    return 0;
}








