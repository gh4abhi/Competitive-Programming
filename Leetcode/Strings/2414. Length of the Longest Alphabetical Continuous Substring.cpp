// Problem Link - https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/

#define ll int

class Solution {
public:
    int longestContinuousSubstring(string s) {
        ll ans = 1;
        ll op = 1;
        for(ll i=1;i<s.length();i++)
        {
            if(s[i]-s[i-1]==1)
                op++;
            else
                op = 1;
            ans = max(ans,op);
        }
        return ans;
    }
};