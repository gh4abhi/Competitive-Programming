// Problem Link - https://leetcode.com/contest/biweekly-contest-84/problems/merge-similar-items/

#define ll int

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<ll>> ans;
        map<ll,ll> m;
        for(auto i:items1)
            m[i[0]] += i[1];
        for(auto i:items2)
            m[i[0]] += i[1];
        for(auto i:m)
        {
            ans.push_back({i.first,i.second});
        }
        return ans;
    }
};