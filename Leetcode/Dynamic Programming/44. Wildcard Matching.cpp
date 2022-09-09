// Problem Link - https://leetcode.com/problems/wildcard-matching/

#define ll int

class Solution {
public:
    
    bool match(string &s, string &p, ll i, ll j,vector<vector<ll>>& dp)
    {
        if(j<0 and i<0)
            return true;
        if(j<0)
            return false;
        if(i<0)
        {
            for(ll k=0;k<=j;k++)
                if(p[k]!='*')
                    return false;
            return true;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==p[j] or p[j]=='?')
            return dp[i][j] = match(s,p,i-1,j-1,dp);
        if(p[j]=='*')
            return dp[i][j] = match(s,p,i-1,j,dp) or match(s,p,i,j-1,dp);
        return false;
    }
    
    bool isMatch(string s, string p) {
        ll m = s.length(), n = p.length();
        vector<vector<ll>> dp(m,vector<ll>(n,-1));
        return match(s,p,m-1,n-1,dp);
    }
};