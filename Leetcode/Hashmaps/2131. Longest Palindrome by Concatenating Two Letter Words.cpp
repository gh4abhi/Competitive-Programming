// Problem Link - https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

#define ll int

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,ll> m;
        for(auto i:words)
            m[i]++;
        ll ans = 0;
        ll ok =0;
        for(auto i:words)
        {
            if(!m[i])
                continue;
            string str = string(1,i[1])+string(1,i[0]);
            m[i]--;
            if(m[str])
                m[str]--, ans++;
            else if(i==str)
                ok = 1;
        }
        return ans*4+ok*2;
    }
};