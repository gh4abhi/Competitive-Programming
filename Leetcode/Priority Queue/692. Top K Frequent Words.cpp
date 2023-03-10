// Problem Link - https://leetcode.com/problems/top-k-frequent-words/

#define ll int

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,ll> m;
        for(auto &i:words)
            m[i]++;
        priority_queue<pair<ll,string>,vector<pair<ll,string>>, greater<pair<ll,string>>> pq;
        for(auto i:m)
            pq.push({-i.second,i.first});
        vector<string> ans;
        while(k--)
            ans.push_back(pq.top().second), pq.pop();
        return ans;
    }
};