// Problem Link - https://leetcode.com/problems/top-k-frequent-elements/

#define ll int

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<ll,ll> m;
        for(auto i:nums)
            m[i]++;
        priority_queue<pair<ll,ll>> pq;
        for(auto i:m)
            pq.push({i.second,i.first});
        vector<ll> ans;
        while(k--)
            ans.push_back(pq.top().second), pq.pop();
        return ans;
    }
};