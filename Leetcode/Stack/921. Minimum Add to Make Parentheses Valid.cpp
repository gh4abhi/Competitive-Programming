// Problem Link - https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

#define ll int
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        ll count = 0;
        for(auto i:s)
        {
            if(i=='(')
                st.push(i);
            else
            {
                if(st.size())
                    st.pop();
                else
                    count++;
            }
        }
        return count + st.size();
    }
};