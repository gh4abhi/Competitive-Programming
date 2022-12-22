// Problem Link - https://www.codechef.com/START70B/problems/PRIMEREVERSE?tab=statement

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{

    ll n; cin >> n;
    string s; cin >> s;
    string t; cin >> t;
    
    if(s.length()!=t.length()) return void(cout<<"NO\n");
    
    ll s0=0, s1=0;
    ll t0 = 0, t1 = 0;
    for(ll i=0; i<s.length(); ++i) {
        if(s[i] == '1') {
            ++s1;
        }
        else if(s[i] == '0') ++s0;
        if(t[i] == '1') {
            ++t1;
        }
        else if(t[i] == '0') ++t0;
    }

    if(s1 == t1 && s0 == t0) cout<<"YES\n";
    else cout<<"NO\n";
    
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}