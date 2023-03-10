// Problem Link - https://leetcode.com/problems/unique-number-of-occurrences/

#define ll int

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<ll,ll> m;
        for(auto i:arr)
        {
            m[i]++;
        }
        map<ll,ll> fr;
        for(auto i:m)
        {
            if(fr.count(i.second)>0)
                return false;
            fr[i.second]++;
        }
        return true;
    }
};
