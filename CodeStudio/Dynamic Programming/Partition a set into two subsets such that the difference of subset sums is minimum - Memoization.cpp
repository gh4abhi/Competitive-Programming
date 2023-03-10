// Problem Link - https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll int

ll mini(ll ind, ll sum, ll ts, vector<ll>&arr, ll n, vector<vector<ll>> &dp)
{
    if(ind==n)
        return abs(ts-2*sum);
   if(dp[ind][sum]!=-1)
       return dp[ind][sum];
    return dp[ind][sum] =  min(mini(ind+1,sum+arr[ind],ts,arr,n,dp),mini(ind+1,sum,ts,arr,n,dp));
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
    ll ts = 0;
    for(auto i:arr)
        ts += i;
    vector<vector<ll>> dp(n,vector<ll>(ts+1,-1));
    return mini(0,0,ts,arr,n,dp);
}
