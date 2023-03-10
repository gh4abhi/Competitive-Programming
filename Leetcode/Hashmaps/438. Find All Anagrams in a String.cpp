// Problem Link - https://leetcode.com/problems/find-all-anagrams-in-a-string/

#define ll int

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,ll> pat;
        for(auto i:p)
            pat[i]++;
        ll m = p.length();
        map<char,ll> orig;
        for(ll i=0;i<m;i++)
            orig[s[i]]++;
        vector<ll> ans;
        ll i;
        for(i=m;i<s.length();i++)
        {
            if(orig==pat)
                ans.push_back(i-m);
            if(orig[s[i-m]]==1)
                orig.erase(s[i-m]);  
            else
                orig[s[i-m]]--;
            orig[s[i]]++;
        }
        if(orig==pat)
            ans.push_back(i-m);
        return ans;
    }
};
