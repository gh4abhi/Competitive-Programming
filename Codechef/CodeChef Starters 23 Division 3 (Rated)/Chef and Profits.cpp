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
    ll x,y,z;
    cin>>x>>y>>z;
    ll num = x*y;
    ll num2 = x*z;
    cout<<num2-num;
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




