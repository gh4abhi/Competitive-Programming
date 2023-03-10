// Problem Link - https://leetcode.com/problems/sort-array-by-increasing-frequency/

#define ll int

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<ll,ll> m;
        for(auto i:nums)
            m[i]++;
        sort(nums.begin(),nums.end(),[&m](ll &a, ll &b){
            if(m[a]!=m[b])
                return m[a]<m[b];
            return a>b;
        });
        return nums;
    }
};