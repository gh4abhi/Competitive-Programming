// Problem Link - https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll int
#define MOD 1000000007

int countPartitions(int n, int d, vector<int> &arr) {
  ll sum = 0;
  for(auto i:arr)
      sum += i;
    if(sum-d<0 or (sum-d)%2!=0)
        return 0;
    
  vector<vector<ll>> dp(n+1,vector<ll>(sum+1,0));
  if(arr[0]==0)
      dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if(arr[0]!=0 and arr[0]<=sum)
        dp[0][arr[0]] = 1;
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<sum+1;j++)
        {
            dp[i][j] = (dp[i-1][j])%MOD;
            if(j>=arr[i])
                dp[i][j] = (dp[i][j]+dp[i-1][j-arr[i]])%MOD;
        }
    }
    return dp[n-1][(sum-d)/2];
}