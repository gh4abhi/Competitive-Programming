// Problem Link - https://leetcode.com/problems/sum-of-all-odd-length-subarrays/

#define ll int

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        ll n = arr.size();
        vector<ll> m(n,0);
        m[0] = arr[0];
        for(ll i=1;i<n;i++)
            m[i] = m[i-1] + arr[i];
        ll op = 0;
        ll ans = 0;
        while(op<n)
        {
            for(ll i=op;i<n;i++)
            {
                ll ok = 0;
                if(i-op-1>=0)
                    ok = m[i-op-1];
                ans += m[i]-ok;
            }
            op+=2;
        }
        return ans;
    }
};