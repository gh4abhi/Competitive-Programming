// Problem Link - https://www.codingninjas.com/codestudio/problems/699917?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
sort(intervals.begin(),intervals.end());
     stack<vector<ll>> st;
        for(auto i:intervals)
        {
            if(st.size()==0)
                st.push(i);
            else
            {
                if(i[0]<=st.top()[1])
                {
                    ll a = st.top()[0];
                    ll b = st.top()[1];
                    st.pop();
                    st.push({a,max(i[1],b)});
                }
                else
                    st.push(i);
            }
        }
        vector<vector<ll>> ans;
        while(st.size())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
