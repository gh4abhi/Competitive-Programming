// Problem Link - https://leetcode.com/problems/out-of-boundary-paths/

#define ll long long
#define MOD 1000000007

class Solution {
public:
    ll DFS(ll m, ll n, ll maxMove, ll i, ll j,vector<vector<vector<ll>>>& dp)
    {
        if(dp[i][j][maxMove]!=-1)
            return dp[i][j][maxMove];
        vector<vector<ll>> move = {{-1,0},{1,0},{0,-1},{0,1}};
        ll ans = 0;
        for(auto k:move)
        {
            if((i+k[0]<0 or i+k[0]>m-1 or j+k[1]<0 or j+k[1]>n-1) and maxMove)
            ans = (ans%MOD + 1%MOD)%MOD;
            else if(maxMove)
                ans = (ans%MOD + DFS(m,n,maxMove-1,i+k[0],j+k[1],dp)%MOD)%MOD;
        }
        return dp[i][j][maxMove] = ans%MOD;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<ll>>> dp(100,vector<vector<ll>>(100,vector<ll>(100,-1)));
        return (int)DFS(m,n,maxMove,startRow,startColumn,dp)%MOD;
    }
};