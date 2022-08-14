// Problem Link - https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll int

int unboundedKnapsack(int n, int W, vector<int> &values, vector<int> &weight)
{
    vector<ll> dp(W+1,0), temp(W+1);
    for(ll i=weight[0];i<W+1;i++)
        dp[i] = (i/weight[0])*values[0];
    for(ll i=1;i<n;i++)
    {
        temp = dp;
        for(ll j=0;j<W+1;j++)
        {
            dp[j] = temp[j];
            if(j-weight[i]>=0)
                dp[j] = max(dp[j],values[i] + dp[j-weight[i]]);
        }
    }
    return dp[W];
}
