// Problem Link - https://www.codechef.com/START31B/problems/SIGNMOVE

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
ll n;
cin>>n;
ll val = 0;
if(n&1)
{
    val = n/2 +1;
}
else
{
    val = n/2;
}

if(n&1)
{
    cout<<-val;
}
else
{
    cout<<val;
}

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
 
 
 
 