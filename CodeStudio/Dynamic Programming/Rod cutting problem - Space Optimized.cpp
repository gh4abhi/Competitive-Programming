// Problem Link - https://www.codingninjas.com/codestudio/problems/800284?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

int cutRod(vector<int> &price, int n)
{
    vector<ll> dp(n+1,0);
    for(ll i=0;i<n+1;i++)
        dp[i] = i*(price[0]);
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<n+1;j++)
        {
            if(j>=i+1)
                dp[j] = max(dp[j],price[i] + dp[j-i-1]);
        }
    }
    return dp[n];
}
