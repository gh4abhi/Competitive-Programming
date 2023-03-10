// Problem Link - https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

#include <bits/stdc++.h>
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

class Solution {
public:
    ll max(ll a, ll b)
    {
        if(a>b)
            return a;
        return b;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)   {
        sort(full(horizontalCuts));
        sort(full(verticalCuts));
        ll rMax = horizontalCuts[0];
        ll cMax = verticalCuts[0];
        for(ll i=1;i<horizontalCuts.size();i++)
            rMax = max(abs(horizontalCuts[i]-horizontalCuts[i-1]),rMax);
        for(ll i=1;i<verticalCuts.size();i++)
            cMax = max(abs(verticalCuts[i]-verticalCuts[i-1]),cMax);
        rMax = max(rMax,h-horizontalCuts[horizontalCuts.size()-1]);
        cMax = max(cMax,w-verticalCuts[verticalCuts.size()-1]);
        ll ans = rMax*cMax;
        ans = ans%MOD;
        return (int)ans;
    }
};