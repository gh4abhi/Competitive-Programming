// Problem Link - https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll int

ll unboundedKnap(int n, int W, vector<int> &values, vector<int> &weight, ll ind, vector<vector<ll>>& dp)
{
    if(ind==0)
    {
        if(W-weight[ind]>=0)
            return (W/weight[ind])*values[ind];
        return 0;
    }
    if(dp[ind][W]!=-1)
        return dp[ind][W];
    ll notTake = unboundedKnap(n,W,values,weight,ind-1,dp);
    ll take = -1e9;
    if(W-weight[ind]>=0)
        take = values[ind] + unboundedKnap(n,W-weight[ind],values,weight,ind,dp);
    return dp[ind][W] = max(take,notTake);
}

int unboundedKnapsack(int n, int W, vector<int> &values, vector<int> &weight)
{
    vector<vector<ll>> dp(n,vector<ll>(1000,-1));
    return unboundedKnap(n,W,values,weight,n-1,dp);
}
