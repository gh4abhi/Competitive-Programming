// Problem Link - https://leetcode.com/problems/longest-string-chain/

#define ll int

class Solution {
public:
    
    bool check(string &s1, string &s2)
    {
        if(s1.length()!=s2.length()+1)
            return false;
        ll i=0;
        ll j=0;
        while(i<s1.length())
        {
            if(s1[i]==s2[j])
                i++,j++;
            else
                i++;
        }
        if(i==s1.length() and j==s2.length())
            return true;
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        ll n = words.size();
        vector<ll> dp(n,1);
        ll ans = 1;
        sort(words.begin(),words.end(),[](string &a, string &b){
            return a.length()<b.length();
        });
        for(ll i=1;i<n;i++)
        {
            for(ll j=i-1;j>=0;j--)
            {
                if(check(words[i],words[j]) and dp[i]<1+dp[j])
                    dp[i] = 1 + dp[j];
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};