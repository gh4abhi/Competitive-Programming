// Problem Link - https://www.codechef.com/START24B/problems/ANTI_PAL

#include<bits/stdc++.h>
#define ll int
#define pb push_back 
#define limit 100001

using namespace std;

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
    string str;
    cin>>str;
    if(n&1)
    {
        cout<<"NO";
        return;
    }
    map<char,ll> m;
    vector<pair<char,ll>> vect;
    for(auto i:str)
    m[i]++;
    for(auto i:m)
    {
    vect.push_back(make_pair(i.first,i.second));
    if(i.second>n/2)
    {
        cout<<"NO";
        return;
    }
    }
    sort(vect.begin(),vect.end(),cmp);
    
    string s = "";
    
    ll a = n/2-1;
    ll b = n/2;
    
    
    for(auto i:vect)
    {
        for(ll j=0;j<i.second;j++)
        {
            s+= i.first;
        }
    }
    ll i = 0;
    while(s[a]==s[b])
    {
        swap(s[a],s[i]);
        i++;
        a--;
        b++;
    }
    cout<<"YES"<<endl<<s;
    
    
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    
}
