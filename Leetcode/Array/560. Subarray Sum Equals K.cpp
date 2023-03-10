// Problem Link - https://leetcode.com/problems/subarray-sum-equals-k/

#define ll int
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
    ll n = arr.size();
    ll curSum = 0;
    map<ll,ll> m;
    ll ans = 0;
    for(ll i=0;i<n;i++)
    {
        curSum+=(arr[i]);
        if(curSum==k)
        {
            ans++;
        }
        if(m.count(curSum - k)>0)
        {
            ans+= m[curSum - k];
        }
        m[curSum]++;
    }

    return ans;   
    }
};
