// Problem Link - https://www.codingninjas.com/codestudio/problems/rahul-and-his-chocolates_3118974?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#define ll int    
    ll maxPro(vector<ll>& prices, ll fee, ll buy, ll i, ll n, vector<vector<ll>> &dp)
    {
        if(i==n)
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy)
            return dp[i][buy] = max(-prices[i] + maxPro(prices,fee,0,i+1,n,dp), maxPro(prices,fee,1,i+1,n,dp));
        return dp[i][buy] = max(prices[i] - fee + maxPro(prices,fee,1,i+1,n,dp), maxPro(prices,fee,0,i+1,n,dp));
    }
    

int maximumProfit(int n, int fee, vector<int> &prices) {
        vector<vector<ll>> dp(n,vector<ll>(2,-1));
        return maxPro(prices,fee,1,0,n,dp);
}
