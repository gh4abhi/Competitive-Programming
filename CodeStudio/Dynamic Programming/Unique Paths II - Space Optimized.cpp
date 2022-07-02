// Problem Link - https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?leftPanelTab=0

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
#define ll int
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
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    ll dp[m];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<m;i++)
    {
        if(mat[0][i]==0)
            dp[i] = 1;
        else
            break;
    }
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {if(j>0)
                    dp[j] = (dp[j-1]%MOD + dp[j]%MOD)%MOD;}
            else
                dp[j] = 0;
        }
    }
    return dp[m-1];
}