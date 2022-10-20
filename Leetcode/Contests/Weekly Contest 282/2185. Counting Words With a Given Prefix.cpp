// Problem Link - https://leetcode.com/contest/weekly-contest-282/problems/counting-words-with-a-given-prefix/

#define ll int

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        ll ans = 0;
        for(auto i:words)
        {
            ll k=0;
            ll n = pref.length();
            while(k<n)
            {
                if(i[k]!=pref[k])
                    break;
                k++;
            }
            if(k==n)
                ans++;
        }
        return ans;
    }
};