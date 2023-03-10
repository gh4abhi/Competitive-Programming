// Problem Link - https://codeforces.com/contest/1642/problem/A

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
    double x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if(y1==y2)
    {
      if(y3<y1)
      {
          cout<<setprecision(9)<<(sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
          return;
      }
    }
    else if(y2==y3)
    {
      if(y1<y3)
      {
          cout<<setprecision(9)<<(sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)));
          return;
      }      
    }
    
    else if(y1==y3)
    {
      if(y2<y3)
      {
          cout<<setprecision(9)<<(sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)));
          return;
      }      
    }
    cout<<setprecision(9)<<0;
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