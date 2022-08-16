// Problem Link - https://leetcode.com/problems/last-stone-weight-ii/

#define ll int

class Solution {
public:
    
    ll lastStone(vector<int>& stones, ll ind, ll sum, ll ts, vector<vector<ll>> &dp)
    {
        if(ind==0)
            return abs(sum - (ts - sum));
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        ll notTake = lastStone(stones,ind-1,sum,ts,dp);
        ll take = lastStone(stones,ind-1,sum+stones[ind],ts,dp);
        return dp[ind][sum] = min(notTake,take);
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        ll sum = 0 ;
        for(auto i:stones)
            sum += i;
        vector<vector<ll>> dp(stones.size(),vector<ll>(sum+1,-1));
        return lastStone(stones,stones.size()-1,0,sum,dp);
    }
};