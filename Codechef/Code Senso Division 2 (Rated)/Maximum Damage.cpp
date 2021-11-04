// Problem Link - https://www.codechef.com/CSNS21C/problems/MAXDMGE/

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


void its_Function() {
    ll n;
    cin>>n;
    vector<ll> vect(n);
    for(ll i=0;i<n;i++)
    {
        cin>>vect[i];
    }
    vector<ll> ans;
    vector<ll> v = vect;
    map<ll,ll> m;
    sort(full(v));
    for(ll i=0;i<n;i++)
    {
        
        if(i==0)
        {
            ans.pb(vect[i]&vect[i+1]);
        }
        else if(i==n-1)
        {
            ans.pb(vect[i]&vect[i-1]);
        }
        else
        {
            ans.pb(max(vect[i]&vect[i+1],max(vect[i]&vect[i-1],vect[i+1]&vect[i]&vect[i-1])));
        }
    }
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}

//--------------------------------------------------------------Main Function----------------------------------------------------------------------------------------------
int main()
{


    ll t;
    cin>>t;
    while(t--)
    {

        its_Function();
        cout<<endl;
    }
//    its_Function();return 0;
}
