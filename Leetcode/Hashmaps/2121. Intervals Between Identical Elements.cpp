// Problem Link - https://leetcode.com/problems/intervals-between-identical-elements/

#define ll long long 

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<ll,vector<ll>> m;
        for(ll i=0;i<arr.size();i++)
            m[arr[i]].push_back(i);
        vector<ll> ans(arr.size(),0);
        for(auto i:m)
        {
            ll sum = 0;
            for(auto j:i.second)
                sum += j;
            ll op = 0;
            ll ok = 0;
            for(auto j:i.second)
            {
                ok += 1;
                ans[j] = abs(sum-op-(ll)(i.second.size()-ok+1)*j) + abs((ok-1)*j-op);
                op += j;
            }
        }
        return ans;
    }
};