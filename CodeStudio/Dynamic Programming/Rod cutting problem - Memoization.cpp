// Problem Link - https://www.codingninjas.com/codestudio/problems/800284?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

ll cut(vector<int> &price, int n, ll ind,vector<vector<ll>> &dp)
{
    if(ind==0)
        return n*price[ind];
    if(dp[ind][n]!=-1)
        return dp[ind][n];
    ll dontCut = cut(price,n,ind-1,dp);
    ll cutIt = -1e9;
    if(n>=ind+1)
        cutIt = price[ind] + cut(price,n-ind-1,ind,dp);
    return dp[ind][n] = max(cutIt,dontCut);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<ll>> dp(n,vector<ll>(n+1,-1));
    return cut(price,n,n-1,dp);
}
