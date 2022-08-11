// Problem Link - https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll long long

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<ll> dp(maxWeight+1,0);
    if(weight[0]<=maxWeight)
        for(ll i=weight[0];i<=maxWeight;i++)
            dp[i] = value[0];
    for(ll i=1;i<n;i++)
    {
        for(ll j=maxWeight;j>=0;j--)
        {
            ll notTake = dp[j];
            ll take = INT_MIN;
            if(j>=weight[i])
                take = max(take,value[i] + dp[j-weight[i]]);
            dp[j] = max(take,notTake);
        }
    }
    return dp[maxWeight];
}