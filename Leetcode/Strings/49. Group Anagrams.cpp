// Problem Link - https://leetcode.com/problems/group-anagrams/

#define ll int

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        for(auto i:strs)
        {
            string op = string(26,'0');
            ll val;
            for(auto j:i)
                val = (op[j-'a'] -'0'),val+=1,op[j-'a'] = '0' + val;
            m[op].push_back(i);
        }
        vector<vector<string>> ans(m.size());
        ll k = 0;
        for(auto i:m)
        {
            for(auto j:i.second)
                ans[k].push_back(j);
            k++;
        }
        return ans;
    }
};