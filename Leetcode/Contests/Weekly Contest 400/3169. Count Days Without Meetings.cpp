// Problem Link - https://leetcode.com/contest/weekly-contest-400/problems/count-days-without-meetings/

#define ll int

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        stack<pair<ll,ll>> st;
        sort(meetings.begin(),meetings.end());
        for(auto i:meetings)
        {
            if(st.size() and st.top().second>i[0])
            {
                auto op = st.top();
                st.pop();
                op.first = min(op.first,i[0]);
                op.second = max(op.second,i[1]);
                st.push(op);
            }
            else
                st.push({i[0],i[1]});
        }
        vector<pair<ll,ll>> ok;
        while(st.size())
            ok.push_back(st.top()), st.pop();
        reverse(ok.begin(),ok.end());
        ll ans = 0;
        ll pre = 1;
        ans += ok[0].first - 1;
        for(ll i=1;i<ok.size();i++)
            ans += max(0,ok[i].first - ok[i-1].second -1);
        ans += days-ok[ok.size()-1].second;
        return ans;
    }
};  