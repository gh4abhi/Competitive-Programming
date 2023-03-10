// Problem Link - https://leetcode.com/problems/longest-common-subsequence/

#define ll int
class Solution {
public:
    int longestCommonSubsequence(string s, string t)    
    {
    ll m = s.length();
    ll n = t.length();
    ll dp[m+1][n+1];
    for(ll i=0; i<=m; i++)
    {
        dp[i][0] = 0;
    }
    for(ll i=0; i<=n; i++)
    {
        dp[0][i] = 0;
    }
    for(ll i=1;i<=m;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(s[m-i]==t[n-j])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                ll a = dp[i-1][j];
                ll b = dp[i][j-1];
                ll c = dp[i-1][j-1];
                dp[i][j] = max(a,max(b,c));
            }
        }
    }
    return dp[m][n];
    }
};
