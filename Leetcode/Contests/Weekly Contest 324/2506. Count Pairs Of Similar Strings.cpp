// Problem Link - https://leetcode.com/contest/weekly-contest-324/problems/count-pairs-of-similar-strings/

#define ll int

class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<string,ll> m;
        for(auto i:words)
        {
            map<char,ll> op;
            string ok = "";
            for(auto j:i)
            {
                if(op.count(j)==0)
                    ok+=j, op[j]++;
            }
            sort(ok.begin(),ok.end());
            m[ok]++;
        }
        ll ans = 0;
        for(auto i:m)
            ans += (i.second*(i.second-1))/2;
        return ans;
    }
};