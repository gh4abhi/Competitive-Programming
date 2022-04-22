// Problem Link - https://leetcode.com/problems/baseball-game/

#define ll int
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<ll> st;
        for(auto i:ops)
        {
            if(i=="C")
                st.pop();
            else if(i=="D")
            {
                ll val = st.top();
                st.push(2*val);
            }
            else if(i=="+")
            {
                ll val1 = st.top();
                st.pop();
                ll val2 = st.top();
                st.push(val1);
                st.push(val1 + val2);
            }
            else
            {
                ll val = stoi(i);
                st.push(val);
            }
        }
        ll sum = 0;
        while(st.size())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};