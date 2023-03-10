// Problem Link - https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

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
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<ll,ll>> pq;
        pq.push({entrance[0],entrance[1]});
        vector<vector<ll>> dp(maze.size(),vector<ll>(maze[0].size(),1e18));
        vector<vector<ll>> need = {{0,1},{1,0},{-1,0},{0,-1}};
        dp[entrance[0]][entrance[1]] = 0;
        while(pq.size())
        {
            pair<ll,ll> cur = pq.front();
            pq.pop();
            for(auto i:need)
            {
                ll x = cur.first + i[0];
                ll y = cur.second + i[1];
                if(x>=0 and y>=0 and x<dp.size() and y<dp[0].size() and maze[x][y]=='.' and dp[x][y]==1e18)
                    dp[x][y] = 1 + dp[cur.first][cur.second], pq.push({x,y});
            }
        }
        ll ans = 1e18;
        for(ll i=0;i<dp.size();i++)
        {
            if(i!=entrance[0] or entrance[1]!=0)
                ans = min(ans,dp[i][0]);
            if(i!=entrance[0] or entrance[1]!=dp[0].size()-1)
            ans = min(ans,dp[i][dp[0].size()-1]);
        }
        for(ll j=0;j<dp[0].size();j++)
        {
            if(entrance[0]!=0 or j!=entrance[1])
                ans = min(ans,dp[0][j]);
            if(entrance[0]!=dp.size()-1 or j!=entrance[1])
                ans = min(ans,dp[dp.size()-1][j]);
        }
        if(ans==1e18)
            return -1;
        return ans;
    }
};