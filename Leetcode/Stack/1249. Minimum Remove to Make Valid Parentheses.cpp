// Problem Link - https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

#define ll int

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        deque<ll> ind;
        
        for(ll i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                ind.push_back(i);
                st.push('(');
            }
            else if(s[i]==')')
            {
                if(st.size()==0)
                    ind.push_front(i);
                else
                {
                    st.pop();
                    ind.pop_back();
                }
            }
        }
        
        vector<ll> vis(s.length());
        while(ind.size())
        {
            ll i = ind.front();
            vis[i] = 1;
            ind.pop_front();
        }
        
        string ans = "";
        for(ll i=0;i<s.length();i++)
        {
            if(vis[i]!=1)
                ans += s[i];
        }
        return ans;
    }
};