// Problem Link - https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll long long

ll dp[100][10000];
ll knap(vector<int> weight, vector<int> value, int n, int maxWeight, ll ind, ll w)
{
    if(ind==weight.size()-1)
    {
        if(weight[ind]+w<=maxWeight)
            return value[ind];
        return 0;
    }
    if(dp[ind][w]!=-1)
        return dp[ind][w];
    ll take = INT_MIN;
    ll notTake = knap(weight,value,n,maxWeight,ind+1,w);
    if(weight[ind]+w<=maxWeight)
        take = value[ind] + knap(weight,value,n,maxWeight,ind+1,w+weight[ind]);
    return dp[ind][w] = max(take,notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    memset(dp,-1,sizeof(dp));
    return knap(weight,value,n,maxWeight,0,0);
}