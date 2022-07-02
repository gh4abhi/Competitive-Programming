// Problem Link - https://www.interviewbit.com/problems/grid-unique-paths/

#define ll int
int Solution::uniquePaths(int A, int B) {
    ll dp[A][B];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<A;i++)
        dp[i][0] = 1;
    for(ll i=0;i<B;i++)
        dp[0][i] = 1;
    for(ll i=1;i<A;i++)
        for(ll j=1;j<B;j++)
            dp[i][j] += dp[i-1][j] + dp[i][j-1];
    return dp[A-1][B-1];
}
