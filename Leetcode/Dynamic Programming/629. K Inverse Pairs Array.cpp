// Problem Link - https://leetcode.com/problems/k-inverse-pairs-array/

#define ll long long
#define MOD 1000000007
class Solution {
public:
    int kInversePairs(int n, int k) {
        ll dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        for(ll i=1;i<n;i++)
            for(ll j=0;j<k;j++)
            {
                if(j==0)
                    dp[i][j] = 1;
                else
                    for(ll r=0;r<=min(i-1,j);r++)
                        dp[i][j] = (dp[i][j] + dp[i-1][j-r])%MOD;
            }
        return dp[n-1][k-1];
    }
};