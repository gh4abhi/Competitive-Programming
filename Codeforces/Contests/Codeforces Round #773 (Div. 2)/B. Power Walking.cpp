// Problem Link - https://codeforces.com/contest/1642/problem/B

#include <bits/stdc++.h>
#define SPEED  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define empb emplace_back
#define mpr make_pair
#define sortit(v) sort(v.begin(), v.end())
#define forl(n) for(ll i=0;i<n;i++)
#define prtIn(vect,i) cout<<vect[i]
#define vecs(vect,n) vector<ll> vect(n)
#define rev(v) reverse(v.begin(), v.end());
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
#define sz size()
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
 
bool isPwerOf2(ll x)
{
    return x && (!(x&(x-1)));
}
 
 
bool cmp(pair<char,ll> a, pair<char,ll> b)
{
    if(a.second!=b.second)
        return a.second>b.second;
    return a.first>b.first;    
}
 
void solve()
{
    ll n;
    cin>>n;
    vector<ll> vect(n);
    map<ll,ll> m;
    for(ll i=0;i<n;i++)
    {
      cin>>vect[i];
      m[vect[i]]++;
    }
    ll nd = m.size();
    ll k=1;
    while(k<=n)
    {
      if(k<=nd)
      {
        cout<<nd<<" ";
      }
      else
      {
        cout<<nd+1<<" ";
        nd++;
      }
      k++;
    }
}
 
int main()
{
    SPEED;
    #ifndef ONLINE_JUDGE
    inOt(); 
    #endif
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    
}