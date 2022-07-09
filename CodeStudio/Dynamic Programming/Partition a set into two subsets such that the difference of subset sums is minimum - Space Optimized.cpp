// Problem Link - https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTab=0

#define ll int
int minSubsetSumDifference(vector<int>& arr, int n)
{
    ll sum = 0;
    for(auto i:arr)
        sum += i;
    vector<ll> dp(sum+1,0);
    dp[0] = 1;
    if(arr[0]<=sum)
        dp[arr[0]] = 1;
    for(ll i=1;i<n;i++)
    {
        vector<ll> temp;
        temp = dp;
        for(ll j=1;j<sum+1;j++)
        {
            dp[j] = temp[j];
            if(j>=arr[i])
                dp[j] = dp[j] or temp[j-arr[i]];
        }
    }
    ll mini = 1e9;
    for(ll i=0;i<=sum/2;i++)
        if(dp[i])
            mini = min(mini,abs((i)-(sum-i)));
    return mini;
}
