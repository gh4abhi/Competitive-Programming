// Problem Link - https://leetcode.com/problems/valid-parentheses/

#define ll int

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        ll n = s.length();
        for(ll i=0;i<n;i++)
        {
            if(st.size()==0 and (s[i]=='}' or s[i]==')' or s[i]==']'))
                return false;
            else if((s[i]=='{' or s[i]=='(' or s[i]=='['))
                st.push(s[i]);
            else if(s[i]=='}' and st.top()!='{')
                return false;
            else if(s[i]==']' and st.top()!='[')
                return false;
            else if(s[i]==')' and st.top()!='(')
                return false;
            else
                st.pop();
        }
        return st.size()==0;
    }
};  