// Problem Link - https://leetcode.com/problems/substring-with-largest-variance/

#define ll int

class Solution {
public:
    int largestVariance(string s) {
        vector<ll> freq(26,0);
        for(auto i:s)
            freq[i-'a']++;
        ll ans = 0;
        for(char ch1 = 'a'; ch1<='z';ch1++)
        {
            for(char ch2 = 'a'; ch2<='z'; ch2++)
            {
                if(ch1==ch2 or freq[ch1-'a']==0 or freq[ch2-'a']==0)
                    continue;
                for(ll j=0;j<2;j++)
                {
                    ll f1 = 0, f2 = 0;
                    for(auto i:s)
                    {
                        if(i==ch1)
                            f1++;
                        if(i==ch2)
                            f2++;
                        if(f2>f1)
                            f1 = 0, f2 = 0;
                        if(f1>0 and f2>0)
                            ans = max(ans,f1-f2);
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};