// Problem Link - https://leetcode.com/problems/concatenated-words/

#define ll int

class Solution {
public:

    vector<string> ans;

    bool concat(ll ind, string &str, unordered_map<string,ll> &m)
    {
        string op = "";
        for(ll i=ind; i<str.length()-1; i++)
        {
            op += str[i];
            if(m.count(op))
            {
                if(m.count(str.substr(i+1,str.length())))
                {
                    ans.push_back(str);
                    return 1;
                }
                else if(concat(i+1,str,m))
                    return 1;
            }
        }
        return 0;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a, string &b){
            return a.length()<b.length();
        });
        unordered_map<string,ll> m;
        for(auto i:words)
            m[i]++;
        for(auto i:words)
            concat(0,i,m);
        return ans;
    }
};