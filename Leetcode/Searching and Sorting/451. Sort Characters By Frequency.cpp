// Problem Link - https://leetcode.com/problems/sort-characters-by-frequency/

#define ll int

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,ll> m;
        for(auto i:s)
            m[i]++;
        sort(s.begin(),s.end(),[&m](char &a, char &b){
            if(m[a]==m[b])
                return a>b;
           return m[a]>m[b];
        });
        return s;
    }
};