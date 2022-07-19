// Problem Link - https://leetcode.com/problems/reverse-words-in-a-string/

#define ll int

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        s+=' ';
        string str = "";
        for(ll i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                while(i+1<s.length() and s[i+1]==' ')
                    i++;
                if(str.length())
                    st.push(str);
                str="";
                continue;
            }
            if(s[i]!=' ')
                str += s[i];
        }
        str = "";
        if(st.size())
            str+=st.top(), st.pop();
        while(st.size())
            str+=' '+st.top(), st.pop();
        return str;
    }
};