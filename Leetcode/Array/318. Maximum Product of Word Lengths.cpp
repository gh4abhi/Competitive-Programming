// Problem Link - https://leetcode.com/problems/maximum-product-of-word-lengths/

#define ll long long

class Solution {
public:
    
    ll max(ll a,ll b)
    {
        if(a>b)
            return a;
        return b;
    }
    
    int maxProduct(vector<string>& words) {
        ll dp[words.size()];
        memset(dp,0,sizeof(dp));
        ll k =0;
        for(auto i:words)
        {
            for(auto j:i)
            {
                ll ind = j-'a';
                dp[k] |= 1ll<<(ind);
            }
            k++;
        }
        ll ans = 0;
        for(ll i=0;i<words.size();i++)
        {
            for(ll j=i+1;j<words.size();j++)
            {
                if((dp[i]&dp[j])==0)
                    ans = max(ans,words[i].length()*words[j].length());
            }
        }
        return (int)ans;
    }
};