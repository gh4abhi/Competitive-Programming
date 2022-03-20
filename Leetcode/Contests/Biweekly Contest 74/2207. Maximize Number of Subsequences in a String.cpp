// Problem Link - https://leetcode.com/contest/biweekly-contest-74/problems/maximize-number-of-subsequences-in-a-string/

#define ll long long

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        vector<ll> p2(text.length()+1,0);
        string fin = pattern[0] + text;
        for(ll i=text.length();i>=0;i--)
        {
            if(i==text.length())
            {
                p2[i] = 0;
                continue;
            }
            if(fin[i+1]==pattern[1])
                p2[i] = 1 + p2[i+1];
            else
                p2[i] = p2[i+1];
        }
        ll count1 = 0;
        for(ll i=0;i<=text.length();i++)
        {
            if(fin[i]==pattern[0])
                count1+=p2[i];
        }
        
        fin = text + pattern[1];
        for(ll i=text.length();i>=0;i--)
        {
            if(i==text.length())
            {
                p2[i] = 0;
                continue;
            }
            if(fin[i+1]==pattern[1])
                p2[i] = 1 + p2[i+1];
            else
                p2[i] = p2[i+1];
        }
        ll count2 = 0;
        for(ll i=0;i<=text.length();i++)
        {
            if(fin[i]==pattern[0])
                count2+=p2[i];
        }
        ll ans = 0;
        ans = max(count1,count2);
        return ans;
    }
};