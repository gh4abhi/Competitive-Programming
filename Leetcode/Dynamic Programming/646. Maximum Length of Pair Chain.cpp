// Problem Link - https://leetcode.com/problems/maximum-length-of-pair-chain/

#define ll int

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<ll> dp(pairs.size(),1);
        ll ans = 1;
        for(ll i=1;i<pairs.size();i++)
            for(ll j=0;j<i;j++)
                if(pairs[j][1]<pairs[i][0])
                    dp[i] = max(dp[i],1+dp[j]), ans = max(ans,dp[i]);
        return ans;
    }
};