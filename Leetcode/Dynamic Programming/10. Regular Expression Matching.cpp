// Problem Link - https://leetcode.com/problems/regular-expression-matching/

#define ll int

class Solution {
public:
    bool match(string &s, string &p, ll i, ll j,vector<vector<ll>>& dp)
    {
        if(j==0 and i==0)
            return true;
        if(j==0)
            return false;
        if(i==0)
        {
            for(ll k=j;k>=1;k-=2)
                if(p[k-1]!='*')
                    return false;
            return true;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i-1]==p[j-1] or p[j-1]=='.')
            return dp[i][j] = match(s,p,i-1,j-1,dp);
        if(p[j-1]=='*')
        {
            if(j>1 and p[j-2]==s[i-1] or p[j-2]=='.')
                return dp[i][j] = match(s,p,i,j-2,dp) or match(s,p,i-1,j,dp);
            return dp[i][j] = match(s,p,i,j-2,dp);
        }
        return false;
    }
    
    bool isMatch(string s, string p) {
        ll m = s.length(), n = p.length();
        vector<vector<ll>> dp(m+1,vector<ll>(n+1,-1));
        return match(s,p,m,n,dp);
    }
};