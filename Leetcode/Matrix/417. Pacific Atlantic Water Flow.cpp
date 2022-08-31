// Problem Link - https://leetcode.com/problems/pacific-atlantic-water-flow/

#define ll int

class Solution {
public:
    
    void DFS(vector<vector<int>>& vect, vector<vector<ll>> &vis, ll i, ll j, vector<vector<pair<ll,ll>>>& dp, ll a, ll b)
    {
        vis[i][j] = 1;
        if(dp[i][j].first==1 or a==1)
            dp[i][j].first = 1;
        if(dp[i][j].second==1 or b==1)
            dp[i][j].second = 1;
        if(i-1>=0 and vis[i-1][j]==0 and vect[i][j]<=vect[i-1][j])
            DFS(vect,vis,i-1,j,dp,dp[i][j].first,dp[i][j].second);
        if(j-1>=0 and vis[i][j-1]==0 and vect[i][j]<=vect[i][j-1])
            DFS(vect,vis,i,j-1,dp,dp[i][j].first,dp[i][j].second);
        if(i+1<vect.size() and vis[i+1][j]==0 and vect[i][j]<=vect[i+1][j])
            DFS(vect,vis,i+1,j,dp,dp[i][j].first,dp[i][j].second);
        if(j+1<vect[0].size() and vis[i][j+1]==0 and vect[i][j]<=vect[i][j+1])
            DFS(vect,vis,i,j+1,dp,dp[i][j].first,dp[i][j].second);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& vect) {
        ll m = vect.size();
        ll n = vect[0].size();
        vector<vector<pair<ll,ll>>> dp(m,vector<pair<ll,ll>>(n));
        vector<vector<ll>> vis(m,vector<ll>(n,0));        
        for(ll i=0;i<m;i++)
            if(vis[i][0]==0)
                DFS(vect,vis,i,0,dp,1,dp[i][0].second);
        for(ll i=0;i<n;i++)
            if(vis[0][i]==0)
                DFS(vect,vis,0,i,dp,1,dp[0][i].second);
        vector<vector<ll>> dummy(m,vector<ll>(n,0));
        vis = dummy;
        for(ll i=0;i<n;i++)
            if(vis[m-1][i]==0)
                DFS(vect,vis,m-1,i,dp,dp[m-1][i].first,1);
        for(ll i=0;i<m;i++)
            if(vis[i][n-1]==0)
                DFS(vect,vis,i,n-1,dp,dp[i][n-1].first,1);
        vector<vector<ll>> ans;
        for(ll i=0;i<m;i++)
            for(ll j=0;j<n;j++)
                if(dp[i][j].first and dp[i][j].second)
                    ans.push_back({i,j});
        return ans;
    }
};