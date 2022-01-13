// Problem Link - https://leetcode.com/problems/merge-intervals/

#define ll int

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<ll>> ans;
        sort(intervals.begin(),intervals.end());
        ll startInterval,endInterval;
        startInterval = intervals[0][0];
        endInterval = intervals[0][1];
        for(ll i=1; i<intervals.size();i++)
        {
            if(startInterval<=intervals[i][0] and endInterval>=intervals[i][0])
            {
                endInterval = max(endInterval,intervals[i][1]);
                startInterval = min(startInterval, intervals[i][0]);
            }
            else if(startInterval>=intervals[i][0] and intervals[i][1]>=endInterval)
            {
                endInterval = max(endInterval,intervals[i][1]);
                startInterval = min(startInterval, intervals[i][0]);
            }
            else if(startInterval>=intervals[i][0] and endInterval>=intervals[i][1]and intervals[i][1]>=startInterval)
            {
                endInterval = max(endInterval,intervals[i][1]);
                startInterval = min(startInterval, intervals[i][0]);
            }
            else 
            {
                vector<ll> tempAns;
                tempAns.push_back(startInterval);
                tempAns.push_back(endInterval);
                ans.push_back(tempAns);
                startInterval = intervals[i][0];
                endInterval = intervals[i][1];
            }
        }
        if(ans.size()==0 or startInterval!= ans[ans.size()-1][0] or endInterval!=ans[ans.size()-1][1])
        {
            vector<ll> tempAns;
                tempAns.push_back(startInterval);
                tempAns.push_back(endInterval);
                ans.push_back(tempAns);
        }
        return ans;
    }
};
