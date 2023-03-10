// Problem Link - https://leetcode.com/problems/decode-xored-array/

#define ll int

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<ll> ans;
        ans.push_back(first);
        for(auto i:encoded)
        {
            ans.push_back(i^first);
            first = i^first;
        }
        return ans;
    }
};
