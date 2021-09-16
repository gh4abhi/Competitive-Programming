// Problem Link - https://leetcode.com/problems/contains-duplicate/

#define ll long long
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<ll,ll> m;
        for(auto i:nums)
        {
            m[i]++;
            if(m[i]>1)
            {
                return true;
            }
        }
        return false;
    }
};
