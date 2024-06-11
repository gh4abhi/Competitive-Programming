// Problem Link - https://leetcode.com/problems/relative-sort-array/?envType=daily-question&envId=2024-06-11

#define ll int

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<ll,ll> m;
        for(ll i=0;i<arr2.size();i++)
            m[arr2[i]] = i;
        sort(arr1.begin(),arr1.end(),[&m](ll &a, ll &b){
            if(!m.count(a) and !m.count(b))
                return a<b;
            if(!m.count(a))
                return false;
            if(!m.count(b))
                return true;
            return m[a]<m[b];
        });
        return arr1;
    }
};