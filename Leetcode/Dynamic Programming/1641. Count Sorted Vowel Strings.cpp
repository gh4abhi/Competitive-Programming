// Problem Link - https://leetcode.com/problems/count-sorted-vowel-strings/

#define ll int

class Solution {
public:
    int countVowelStrings(int n) {
      vector<vector<ll>> dp(n,vector<ll>(5));
        ll sum = 5;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<5;j++)
            {
                if(i==0 and j==0)
                    dp[i][j] = 1;
                else if(i==0)
                    dp[i][j] = 1 + dp[i][j-1];
                else if(j==0)
                    dp[i][j] = dp[i-1][4];
                else
                    dp[i][j] = dp[i-1][4] - dp[i-1][j-1] + dp[i][j-1];
            }
        }
        return dp[n-1][4];
    }
};