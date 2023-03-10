// Problem Link - https://www.codechef.com/submit/XORMUL?tab=statement

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define complete(v) v.begin(), v.end()
#define print(x) cout<<x<<'\n';
#define print2(x,y) cout<<x<<' '<<y<<'\n';

void solve()
{
    ll n,a,b; cin >> n >> a >> b;
    ll x = 0;
    ll tmp = -1;
    ll i = n-1;
    while(i >= 0) {
        if (((1<<i)&a)>0 && ((1<<i)&b)>0) {
            i--;
            continue;
        }
        
        else if (((1<<i)&a)==0 && ((1<<i)&b)==0) x |= (1<<i);
        
        else{
            if (tmp==-1){
                if (((1<<i)&a)==0 && ((1<<i)&b)>0) tmp = 0;
                else{
                    tmp = 0;
                    x |= (1<<i);
                }
            }
            else{
                if (((1<<i)&a)==0 && ((1<<i)&b)>0) x |= (1<<i);
            }
        }
        
        i--;
    }
    cout<<x<<endl;
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