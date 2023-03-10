// Problem Link - https://leetcode.com/problems/daily-temperatures/

#define ll int

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<ll,ll>> st;
        st.push({INT_MAX,-1});
        vector<ll> ans(temperatures.size());
        for(ll i=temperatures.size()-1;i>=0;i--)
        {
            while(st.top().first<=temperatures[i])
                st.pop();
            if(st.top().second==-1)
                ans[i] = 0;
            else
                ans[i] = st.top().second - i;
            st.push({temperatures[i],i});
        }
    return ans;
    }
};