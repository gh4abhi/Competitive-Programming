// Problem Link - https://leetcode.com/problems/distinct-subsequences-ii/

#define ll long long 
#define MOD (ll)(1e9 + 7)

class Solution {
public:
    int distinctSubseqII(string s) {
        ll n = s.length();
        vector<ll> dp(n+1,0);
        dp[0] = 1;
        map<char,ll> m;
        for(ll i=1;i<n+1;i++)
        {
            dp[i] = ((2%MOD)*(dp[i-1]%MOD))%MOD;
            dp[i] = dp[i]%MOD;
            if(m.count(s[i-1])!=0)
            {
                dp[i] = ((dp[i]%MOD)-(dp[m[s[i-1]]-1]%MOD))%MOD;
            }
            dp[i] = dp[i]%MOD;
            m[s[i-1]] = i;
        }
        if(dp[n] < 0) dp[n] += MOD;
        return (dp[n]-1)%MOD;
    }
};
