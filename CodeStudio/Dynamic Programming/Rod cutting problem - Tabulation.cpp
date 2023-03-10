// Problem Link - https://www.codingninjas.com/codestudio/problems/800284?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

int cutRod(vector<int> &price, int n)
{
    vector<vector<ll>> dp(n,vector<ll>(n+1,-1));
    for(ll i=0;i<n+1;i++)
        dp[0][i] = i*(price[0]);
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<n+1;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=i+1)
                dp[i][j] = max(dp[i][j],price[i] + dp[i][j-i-1]);
        }
    }
    return dp[n-1][n];
}