// Problem Link - https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll int

int unboundedKnapsack(int n, int W, vector<int> &values, vector<int> &weight)
{
    vector<vector<ll>> dp(n,vector<ll>(1000,0));
    for(ll i=weight[0];i<W+1;i++)
        dp[0][i] = (i/weight[0])*values[0];
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<W+1;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j-weight[i]>=0)
                dp[i][j] = max(dp[i][j],values[i] + dp[i][j-weight[i]]);
        }
    }
    return dp[n-1][W];
}