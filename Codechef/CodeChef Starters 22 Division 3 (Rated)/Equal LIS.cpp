// Problem Link - https://www.codechef.com/problems/EQLIS

#include <bits/stdc++.h>
#define SPEED  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define prt1(a) cout<<a<<" ";
#define prt2(a,b) cout<<a<<" "<<b<<" ";
#define prt3(a,b,c) cout<<a<<" "<<b<<" "<<c<<" ";
#define ll long long
#define vec  vector<ll>
#define pb push_back
#define pa vector<pair<ll,ll>>
#define fi first
#define se second
#define empb emplace_back
#define mpr make_pair
#define sortit(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define issorted(v) is_sorted(v.begin(),v.end())
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

void solve_function() {
ll n;
cin>>n;
if(n==2)
{
    cout<<"NO";
    return;
}
cout<<"YES"<<endl;
if(n&1)
{
    ll limit = (n+1)/2-1;
    for(ll i = (1+limit); i>=2;i--)
    {
        cout<<i<<" ";
    }
    cout<<1<<" ";
    for(ll i = (n+1)/2+1; i<=n;i++)
    {
        cout<<i<<" ";
    }
}
else
{
    if(n==4)
    {
        cout<<"3 1 4 2";
        return;
    }
    vector<ll> ans;
    for(ll i=1;i<=n/2;i++)
    {
        ans.pb(i);
    }
    for(ll i=n;i>n/2;i--)
    {
        ans.pb(i);
    }
    swap(ans[0], ans[n-1]);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}
}

int main()
{

    SPEED;
#ifndef ONLINE_JUDGE
    inOt();
#endif
    cout<<fixed;

    ll t;
    cin>>t;
    while(t--)
    {
        solve_function();
        cout<<endl;
    }
//    solve_function();

    return 0;
}








