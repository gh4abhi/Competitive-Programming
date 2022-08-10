// Problem Link - https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll int
#define MOD 1000000007

int countPartitions(int n, int d, vector<int> &arr) {
  ll sum = 0;
  for(auto i:arr)
      sum += i;
    if(sum-d<0 or (sum-d)%2!=0)
        return 0;
    
  vector<ll> dp(sum+1,0);
  if(arr[0]==0)
      dp[0] = 2;
    else
        dp[0] = 1;
    if(arr[0]!=0 and arr[0]<=sum)
        dp[arr[0]] = 1;
    vector<ll> temp;
    for(ll i=1;i<n;i++)
    {
        temp = dp;
        for(ll j=0;j<sum+1;j++)
        {
            dp[j] = (temp[j])%MOD;
            if(j>=arr[i])
                dp[j] = (dp[j]+temp[j-arr[i]])%MOD;
        }
    }
    return dp[(sum-d)/2];
}