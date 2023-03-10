// Problem Link - https://leetcode.com/problems/most-beautiful-item-for-each-query/

#define ll int

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<ll,ll> dp;
        for(auto i:items)
            dp[i[0]] = max(i[1],dp[i[0]]);
        ll maxi = dp.begin()->second;
        for(auto& i:dp)
            i.second = max(maxi,i.second), maxi = max(maxi,i.second);
        vector<ll> ans;
        for(auto i:queries)
        {
            auto it = dp.upper_bound(i);
            if(it==dp.end())
                it--,ans.push_back(it->second);
            else
            {
                if(it==dp.begin())
                    ans.push_back(0);
                else
                    it--, ans.push_back(it->second);
            }
        }
        return ans;
    }
};