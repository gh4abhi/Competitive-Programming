// Problem Link - https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

#define ll int

class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        ll start = 0;
        ll end = 0;
        map<char,ll> m;
        ll mostFreq = 0;
        ll maxLen = 0;
        while(end<s.length())
        {
            m[s[end]]++;
            mostFreq = max(m[s[end]], mostFreq);
            if(end-start+1-mostFreq>k)
            {
                m[s[start]]-=1;
                start++;
            }
            maxLen = max(maxLen,end-start+1);
            end++;
        }
        return maxLen;
    }
};