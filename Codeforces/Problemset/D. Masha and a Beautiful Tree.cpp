#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> vect;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        vect.push_back({a,b});
    }
    sort(vect.begin(),vect.end(),[](vector<ll> &a, vector<ll> &b){
        return a[1]-a[0]>b[1]-b[0];
    });
    stack<vector<ll>> st;
    sort(vect.begin(),vect.begin()+k);
    for(ll i=0;i<k;i++)
    {
        if(st.size()==0)
            st.push(vect[i]);
        else
        {
            if(vect[i][0]<=st.top()[1])
            {
                ll a = max(st.top()[0],vect[i][0]);
                ll b = min(vect[i][1],st.top()[1]);
                st.pop();
                st.push({a,b}); 
            }
        }
    }
    ll ans = 0;
    while(st.size())
        ans = max(ans,st.top()[1]-st.top()[0]), st.pop();
    cout<<ans;
}