// Problem Link - https://leetcode.com/problems/binary-trees-with-factors/

#define ll long long
#define MOD 1000000007

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        ll n = arr.size();
        vector<ll> dp(n,1);
        map<ll,ll> m;
        for(ll i=0;i<arr.size();i++)
            m[arr[i]] = i;
        ll ans = 0;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(arr[i]%arr[j]==0 and m.count(arr[i]/arr[j]))
                {
                    if(arr[i]/arr[j]==arr[j])
                        dp[i]  = (dp[i] + dp[j]*dp[j])%MOD;
                    else
                        dp[i] = (dp[i] + dp[j]*dp[m[arr[i]/arr[j]]])%MOD;
                }
            }
            ans = (ans + dp[i])%MOD;
        }
        return ans;
    }
};