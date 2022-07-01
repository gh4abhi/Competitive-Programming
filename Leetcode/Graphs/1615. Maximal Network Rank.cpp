// Problem Link - https://leetcode.com/problems/maximal-network-rank/

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
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<ll,vector<ll>> adjList;
        for(auto i:roads)
        {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        for(ll i=0;i<n;i++)
            sort(full(adjList[i]));
        ll ans = 0;
        for(ll i=0;i<n;i++)
        {
            for(ll j = i+1; j<n;j++)
            {
                if(i==j)
                    continue;
                ll val = adjList[i].size() + adjList[j].size();
                if(binary_search(full(adjList[i]),j))
                    val-=1;
                ans = max(ans,val);
            }
        }
        return ans;
    }
};