// Problem Link - https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

#define ll int
class Solution {
public:
    int minSwaps(string s) {
        map<char,ll> m;
        ll a = s.length()/2;
        ll b = s.length()/2;
        stack<ll> st;
        ll count = 0;
        for(auto i:s)
        {
            if(st.size()==0 and i==']' and a)
                count++, st.push('['), a--;
            else if(i=='[' and a)
                st.push('['),a--;
            else if(i==']' and b)
                st.pop(),b--;
        }
        return count;
    }
};