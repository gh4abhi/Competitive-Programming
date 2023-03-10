// Problem Link - https://leetcode.com/problems/evaluate-reverse-polish-notation/

#define ll long long

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<ll> st;
        for(auto i:tokens)
        {
            if(i=="+")
            {
                ll b = st.top();
                st.pop();
                ll a = st.top();
                st.pop();
                st.push(a+b);
            }
            else if(i=="-")
            {
                ll b = st.top();
                st.pop();
                ll a = st.top();
                st.pop();
                st.push(a-b);
            }
            else if(i=="*")
            {
                ll b = st.top();
                st.pop();
                ll a = st.top();
                st.pop();
                st.push(a*b);
            }
            else if(i=="/")
            {
                ll b = st.top();
                st.pop();
                ll a = st.top();
                st.pop();
                ll c;
                if(b==0)
                    c = 0;
                else
                    c = a/b;
                st.push(c);
            }
            else
                st.push(stoi(i));
        }
        return st.top();
    }
};