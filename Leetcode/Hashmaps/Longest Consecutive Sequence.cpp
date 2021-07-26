// Problem Link - https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& vect) {
        map<int,pair<bool,int>> m;
    int k=0;
    for(auto i:vect)
    {
        m[i].first = true;
        m[i].second = k;
        k++;
    }
    int start = INT_MAX, end = INT_MIN,lStreak=0;
    for(auto i:vect)
    {
        if(m[i].first)
        {
        int curEnd = i, curStart = i,curStreak=1;
        m[i].first = false;
        while(m.count(curStart-1)>0 and m[curStart-1].first)
        {
            curStart -=1;
            curStreak+=1;
            m[curStart].first = false;
        }
        while(m.count(curEnd+1)>0 and m[curEnd+1].first)
        {
           curEnd = curEnd+1;
           m[curEnd].first = false;
           curStreak+=1;
        }
        if(curStreak>lStreak or(curStreak==lStreak and m[curStart].second<m[start].second))
        {
            lStreak = curStreak;
            start = curStart;
            end = curEnd;
        }
        }
    }
       return lStreak;
    }
};
