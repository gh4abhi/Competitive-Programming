// Problem Link - https://www.codechef.com/problems/HS08TEST

#include <bits/stdc++.h>
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
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
 
 
void solve() {
 double x,y;
 cin>>x>>y;
 ll v = x/5;
 double z = x/5;
 if(x+0.5<=y and v==z)
    cout<<(y-x-0.5);
 else
    cout<<y;
}
 
int main()
{
 
    BOOST;
    cout<<fixed;
    /*ll t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }*/
    solve();
    return 0;
}
 
 
 
 