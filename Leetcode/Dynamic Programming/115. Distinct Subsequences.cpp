// Problem Link - https://leetcode.com/problems/distinct-subsequences/

#define ll int
#define MOD 1000000007

class Solution {
public:
    int numDistinct(string s, string t) {
        ll m = s.length();
        ll n = t.length();
        
        ll dp[n+1][m+1];
        
        for(ll i=0;i<n+1;i++)
        {
            for(ll j=0;j<m+1;j++)
            {
                if(i==0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                if(j==0)
                {
                    dp[i][j] = 0;
                    continue;
                }
                if(s[j-1]==t[i-1])
                {
                    dp[i][j] = (dp[i][j-1]%MOD + dp[i-1][j-1]%MOD)%MOD;
                }
                else
                {
                    dp[i][j] = dp[i][j-1]%MOD;
                }
                dp[i][j] = dp[i][j]%MOD;
            }
        }
        
        return dp[n][m];
    }
};
