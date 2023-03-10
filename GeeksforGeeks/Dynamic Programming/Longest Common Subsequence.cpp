// Porblem Link - https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1#

#define ll int
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        ll n = s1.length();
        ll m = s2.length();
        ll dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(ll i=n-1;i>=0;i--)
        {
            for(ll j=m-1;j>=0;j--)
            {
                if(s1[i]==s2[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};