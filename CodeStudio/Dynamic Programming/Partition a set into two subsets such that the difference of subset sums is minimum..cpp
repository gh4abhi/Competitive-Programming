// Problem Link - https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTab=0

#define ll int
int minSubsetSumDifference(vector<int>& arr, int n)
{
    ll sum = 0;
    for(auto i:arr)
        sum += i;
    vector<vector<ll>> dp(n,vector<ll>(sum+1,0));
    for(ll i=0;i<n;i++)
        dp[i][0] = 1;
    if(arr[0]<=sum)
        dp[0][arr[0]] = 1;
    for(ll i=1;i<n;i++)
    {
        for(ll j=1;j<sum+1;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=arr[i])
                dp[i][j] = dp[i][j] or dp[i-1][j-arr[i]];
        }
    }
    ll mini = 1e9;
    for(ll i=0;i<=sum/2;i++)
        if(dp[n-1][i])
            mini = min(mini,abs((i)-(sum-i)));
    return mini;
}
