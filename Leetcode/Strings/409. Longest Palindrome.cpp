// problem Link - https://leetcode.com/problems/longest-palindrome/

#define ll long long

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,ll> m;
        for(auto i:s)
            m[i]++;
        ll ans = 0;
        ll ok = 1;
        for(auto i:m)
        {
            if(i.second&1 and ok)
                ans += 2ll*(i.second/2ll)+1, ok = 0;
            else
                ans += 2ll*(i.second/2ll);
        }
        return ans;
    }
};