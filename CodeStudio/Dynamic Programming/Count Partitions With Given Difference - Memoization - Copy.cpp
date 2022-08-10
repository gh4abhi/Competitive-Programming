// Problem Link - https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll int
#define MOD 1000000007
ll dp[51][10000];
ll countPart(ll n, vector<ll> &arr, ll d, ll sum, ll ts, ll ind)
{
    if(ind==arr.size())
    {
        if(sum==d)
        {
            return 1;
        }
        return 0;
    }
    if(dp[ind][sum]!=-1)
        return dp[ind][sum];
    ll ans = (countPart(n,arr,d,sum+arr[ind],ts,ind+1) + countPart(n,arr,d,sum,ts,ind+1))%MOD;
    return dp[ind][sum] = ans;
}

int countPartitions(int n, int d, vector<int> &arr) {
 memset(dp,-1,sizeof(dp));
 ll sum = 0;
    for(auto i:arr)
        sum += i;
    if((sum-d)<0 or (sum-d)%2!=0)
        return 0;
    return countPart(n,arr,(sum-d)/2,0,sum,0);
}

