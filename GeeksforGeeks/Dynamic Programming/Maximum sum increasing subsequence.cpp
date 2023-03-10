// Problem Link - https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

#define ll int 

class Solution{
        

    public:
    int maxSumIS(int arr[], int n)  
    {  
            vector<ll> dp(n+1);
    dp[n] = 0;
    vector<ll> temp;
    ll ans = 0;
    for(ll i=n-1;i>=0;i--)
    {
        temp = dp;
        for(ll pre=-1;pre<i;pre++)
        {
            if(pre==-1 or arr[i]>arr[pre])
                dp[pre+1] = max(dp[pre+1],arr[i]+temp[i+1]);
            dp[pre+1] = max(dp[pre+1],temp[pre+1]);
        }
    }
    return dp[0];
    }  
};