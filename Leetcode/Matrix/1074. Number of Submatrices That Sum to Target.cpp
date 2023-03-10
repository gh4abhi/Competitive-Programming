// Problem Link - https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

#define ll long long

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        ll ans = 0;
        ll m = matrix.size();
        ll n = matrix[0].size();
        for(ll i=0;i<m;i++)
        {
            vector<ll> dp(n,0);
            for(ll j=i;j<m;j++)
            {
                for(ll k=0;k<n;k++)
                    dp[k] += matrix[j][k];
                map<ll,ll> m;
                m[0]++;
                ll sum = 0;
                for(ll k=0;k<n;k++)
                {
                    sum += dp[k];
                    if(m.count(sum-target))
                        ans+=m[sum-target];
                    m[sum]++;
                }
            }
        }
        return ans;
    }
};