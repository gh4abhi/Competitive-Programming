// Problem Link - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#define ll int

class Solution{
public:
ll matrixMulti(ll arr[], ll n, ll i, ll j,vector<vector<ll>> &dp)
{
    if(i==j)
        return 0;
    ll ans = INT_MAX;
    if(dp[i][j]!=-1)
        return dp[i][j];
    for(ll k=i;k<j;k++)
        ans = min(ans,arr[i-1]*arr[k]*arr[j] + matrixMulti(arr,n,i,k,dp) + matrixMulti(arr,n,k+1,j,dp));
    return dp[i][j] = ans;
}
    int matrixMultiplication(int N, int arr[])
    {
            vector<vector<ll>> dp(N,vector<ll>(N,-1));
    return matrixMulti(arr,N,1,N-1,dp);
    }
};
