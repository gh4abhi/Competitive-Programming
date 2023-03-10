// Longest Increasing Subsequence using DP

#include<bits/stdc++.h>
#define ll long long
#define Nil -1
using namespace std;

ll longest_Sub(vector<ll> vect)
{
    vector<ll> v(vect.size());
    v[0] = 1;
    for(ll i=1;i<vect.size();i++)
    {
        v[i] = 1;
        for(ll j=0;j<i;j++)
        {
            if(vect[j]<vect[i] and v[i]<v[j]+1)
            {
                v[i] = v[j] + 1;
            }
        }
    }
   
    return *max_element(v.begin(),v.end());
}
int main()
{
    ll n;
    cin>>n; //SIZE OF THE ARRAY
    vector<ll> vect(n);
    for(ll i=0;i<n;i++)
    {
        cin>>vect[i];
    }
    
ll res =  longest_Sub(vect);
cout<<res;
}
