// Problem Link - https://leetcode.com/contest/biweekly-contest-90/problems/words-within-two-edits-of-dictionary/

#define ll int

class Solution {
public:
    vector<string> twoEditWords(vector<string>& words, vector<string>& dict) {
        map<ll,ll> m;
        for(ll i=0;i<words.size();i++)
        {
            for(ll j=0;j<dict.size();j++)
            {
                ll count = 0;
                for(ll k=0;k<words[i].size();k++)
                {
                    if(words[i][k]!=dict[j][k])
                        count++;
                }
                if(count<=2)
                {
                    m[i] = 1;
                    break;
                }
            }
        }
        vector<string> ans;
        for(ll i=0;i<words.size();i++)
        {
            if(m.count(i))
                ans.push_back(words[i]);
        }
        return ans;
    }
};