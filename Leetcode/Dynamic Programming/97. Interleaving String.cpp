// Problem Link - https://leetcode.com/problems/interleaving-string/

// Recursive Approach

/*#define ll int

class Solution {
public:
    
    bool isInterleaveHelper(string s1, string s2, string s3, ll i, ll j)
    {
        if(i==s1.length() and j==s2.length())
            return true;
        if(i<s1.length() and s1[i]==s3[i+j])
            if(isInterleaveHelper(s1,s2,s3,i+1,j))
                return true;
        if(j<s2.length() and s2[j]==s3[i+j])
            if(isInterleaveHelper(s1,s2,s3,i,j+1))
                return true;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())
            return false;
        return isInterleaveHelper(s1,s2,s3,0,0);
    }
};*/

// Memoization Approach

/*#define ll int

class Solution {
public:
    
    bool isInterleaveHelper(string s1, string s2, string s3, ll i, ll j, vector<vector<ll>>& dp)
    {
        if(i==s1.length() and j==s2.length())
            return true;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i<s1.length() and s1[i]==s3[i+j])
            if(isInterleaveHelper(s1,s2,s3,i+1,j,dp))
            {
                dp[i][j] = true;
                return true;
            }
            else
                dp[i][j]=false;
        if(j<s2.length() and s2[j]==s3[i+j])
            if(isInterleaveHelper(s1,s2,s3,i,j+1,dp))
             {
                dp[i][j] = true;
                return true;
             }
            else
                dp[i][j]=false;
        dp[i][j] = false;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())
            return false;
        vector<vector<ll>> dp(s1.length()+1,vector<ll>(s2.length()+1,-1));
        return isInterleaveHelper(s1,s2,s3,0,0,dp);
    }
};*/

// Tabulation Approach (2D DP)

/*#define ll int

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        ll n = s1.length();
        ll m = s2.length();
        if(m+n!=s3.length())
            return false;
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        for(ll i=0;i<n+1;i++)
        {
            for(ll j=0;j<m+1;j++)
            {
                if(i==0 and j==0)
                {
                    dp[i][j] = true;
                }
                else if(i==0)
                {
                    if(s2[j-1]==s3[i+j-1])
                        dp[i][j] = dp[i][j-1];
                }
                else if(j==0)
                {
                    if(s1[i-1]==s3[i+j-1])
                        dp[i][j] = dp[i-1][j];
                }
                else
                {
                    if(s2[j-1]==s3[i+j-1])
                        dp[i][j] = dp[i][j-1];
                    if(s1[i-1]==s3[i+j-1])
                        dp[i][j] = dp[i][j]?true:dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};*/

// Tabulation (1D DP)

#define ll int

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        ll n = s1.length();
        ll m = s2.length();
        if(m+n!=s3.length())
            return false;
        vector<bool> dp(m+1,false);
        for(ll i=0;i<n+1;i++)
        {
            for(ll j=0;j<m+1;j++)
            {
                if(i==0 and j==0)
                {
                    dp[j] = true;
                }
                else if(i==0)
                {
                    dp[j] = dp[j-1] and s2[j-1]==s3[i+j-1];
                }
                else if(j==0)
                {
                    dp[j] = dp[j] and s1[i-1]==s3[i+j-1];
                }
                else
                {
                    dp[j] = (dp[j-1] and s2[j-1]==s3[i+j-1]) or (dp[j] and s1[i-1]==s3[i+j-1]);
                }
            }
        }
        return dp[m];
    }
};
