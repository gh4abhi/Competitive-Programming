// Problem Link - https://leetcode.com/contest/weekly-contest-308/problems/removing-stars-from-a-string/

#define ll int

class Solution {
public:
    
    string ans = "";
    
    void remove(string s)
    {
        stack<char> st;
        for(auto i:s)
        {
            if(st.size()==0)
            {
                st.push(i);
                continue;
            }
            else
            {
                if(st.top()!='*' and i=='*')
                    st.pop();
                else
                    st.push(i);
            }
        }
        string temp = "";
        while(st.size())
        {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        ans = temp;
    }
    
    string removeStars(string s) {
        remove(s);
        return ans;
    }
};