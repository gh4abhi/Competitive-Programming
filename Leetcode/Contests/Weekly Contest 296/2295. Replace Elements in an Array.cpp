//Problem Link - https://leetcode.com/contest/weekly-contest-296/problems/replace-elements-in-an-array/

#define ll int

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& vect) {
        map<ll,ll> m;
        for(ll i=0;i<nums.size();i++)
        {
            m[nums[i]] = i;
        }
        for(auto i:vect)
        {
            nums[m[i[0]]] = i[1];
            m[i[1]] = m[i[0]];
            m.erase(i[0]);
        }
        return nums;
    }
};