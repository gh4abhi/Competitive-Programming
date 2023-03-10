// Problem Link - https://leetcode.com/problems/non-overlapping-intervals/

#define ll int

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        ll count = 0;
        ll mini, maxi;
        for(ll i=0;i<intervals.size();i++)
        {
            if(i==0)
            {
                mini = intervals[i][0];
                maxi = intervals[i][1];
                continue;
            }
            if(intervals[i][0]<maxi)
            {
                if(maxi>=intervals[i][1])
                {
                    mini = intervals[i][0];
                    maxi = intervals[i][1];
                }
                count++;
            }
            else
            {
                    mini = intervals[i][0];
                    maxi = intervals[i][1];
            }
        }
        return count;
    }

