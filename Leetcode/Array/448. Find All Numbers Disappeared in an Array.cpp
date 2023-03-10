// Problem Link - https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

#define ll int

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
     map<ll,ll> m;
     for(ll i=1;i<=nums.size();i++)
     {
         m[i] = 0;
     }
     for(auto i:nums)
     {
         m[i]++;
     }
        vector<ll> ans;
        for(auto i:m)
        {
            if(i.second==0)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
