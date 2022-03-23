// Problem Link - https://www.codechef.com/START31B/problems/XORAND

/*-----------------------------------------------------------------
                    Gamers Never Quit.
-------------------------------------------------------------------*/
 
#include <bits/stdc++.h>
#define FAST_IO  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define mpr make_pair
#define sortit(v) sort(v.begin(), v.end())
#define forl(n) for(ll i=0;i<n;i++)
#define rev(v) reverse(v.begin(), v.end());
#define issorted(v) is_sorted(v.begin(),v.end())
#define ll long long
#define vec  vector<ll>
#define pb push_back
#define pa vector<pair<ll,ll>>
#define fi first
#define se second
#define sz size()
#define full(a) a.begin(),a.end()
#define max_val INT_MIN
#define min_val INT_MAX;
#define MOD 1000000007
 
 
using namespace std;
 
 
void Solve() {
/*ll n;
cin>>n;
for(ll i=1;i<=n;i++)
{
    ll a = 27^i;
    ll b = 27&i;
    if(a<b)
    {
    cout<<i<<"-"<<endl;    
    cout<<a<<" "<<b<<endl;
    }
}*/
/*ll a = 16^17;
ll b = 16&17;
cout<<a<<" "<<b;*/
ll n;
cin>>n;
map<string,ll> m;
vector<ll> vect(n);
ll a;
for(ll i=0;i<n;i++)
{
    cin>>vect[i];
    a = log(vect[i])/log(2);
ll temp = a;
a = 1;
while(temp--)
{
a*=2;
}
ll b = 2*a;
string str = to_string(a) + "-" + to_string(b);
m[str]++;
// cout<<a<<" "<<b<<endl;

}
ll ans = 0;
for(auto i:m)
{
    ll num = i.second;
    ans += ((num)*(num-1))/2;
}
cout<<ans;
}
 
int main()
{
 
    FAST_IO;
    cout<<fixed;
    ll t;
    cin>>t;
    while(t--)
    {
        Solve();
        cout<<endl;
    }
//    Solve();
 
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 
 
 