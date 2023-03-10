// Problem Link - https://leetcode.com/contest/biweekly-contest-77/problems/count-prefixes-of-a-given-string/

#define ll int

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        ll ans = 0;
        for(auto i:words)
        {
            if(i.length()<=s.length())
            {
                ll k = 0, check = 0;
                for(ll j = 0;j<i.length();j++)
                {
                    if(i[j]==s[k++])
                        check++;
                }
                if(check==i.length())
                    ans ++;
            }
        }
        return ans;
    }
};