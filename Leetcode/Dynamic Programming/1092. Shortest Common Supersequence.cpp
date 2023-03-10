// Problem Link - https://leetcode.com/problems/shortest-common-supersequence/

#define ll long long

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        ll m = str1.length();
        ll n = str2.length();
        vector<vector<ll>> dp(m+1,vector<ll>(n+1,0));
        for(ll i=1;i<m+1;i++)
        {
            for(ll j=1;j<n+1;j++)
            {
                if(str1[i-1]==str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        ll i = m, j = n;
        string ans = "";
        while(i>0 and j>0)
        {
            if(str1[i-1]==str2[j-1])
                ans += str1[i-1],i--,j--;
            else if(dp[i-1][j]>dp[i][j-1])
                ans += str1[i-1],i--;
            else
                ans += str2[j-1],j--;
        }
        if(i==0)
            while(j>0)
                ans += str2[j-1],j--;
        else
            while(i>0)
                ans += str1[i-1],i--;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};