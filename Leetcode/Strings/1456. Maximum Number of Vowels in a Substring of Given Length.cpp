// Problem Link - https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

#define ll int

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char,ll> m = {{'a',1},{'e',1},{'i',1},{'o',1},{'u',1}};
        ll op = 0;
        ll ans = 0;
        ll start = 0, end = 0;
        while(end<s.length())
        {
            if(m.count(s[end]))
                op++;
            if(end-start+1==k)
            {
                ans = max(ans,op);
                if(m.count(s[start]))
                    op--;
                start++;
            }
            end++;
        }
        return ans;
    }
};