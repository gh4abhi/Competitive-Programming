// Problem Link - https://leetcode.com/problems/remove-covered-intervals/

#define ll int

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<vector<ll>> st;
        ll count = 0;
        for(auto i:intervals)
        {
            if(st.empty())
            {
                st.push(i);
                continue;
            }
            vector<ll> t = st.top();
            if(i[1]<=t[1] or (t[0]==i[0] and t[1]<=i[1]))
            {
                st.pop();
                t[0] = min(t[0],i[0]);
                t[1] = max(t[1],i[1]);
                st.push(t);
                count++;
            }
            else
            {
                st.push(i);
            }
        }
        return intervals.size()-count;
    }
};