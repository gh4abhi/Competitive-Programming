// Problem Link - https://leetcode.com/contest/weekly-contest-291/problems/k-divisible-elements-subarrays/

#define ll long long

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
       map<vector<ll>,ll> m;
        for(ll i=0;i<nums.size();i++)
        {
            vector<ll> temp;
            temp.push_back(nums[i]);
            ll val = 0;
            if(nums[i]%p==0)
                val+=1;
            if(val>k)
                continue;
            m[temp]++;
            for(ll j=i+1;j<nums.size();j++)
            {
                if(nums[j]%p==0)
                    val+=1;
                if(val>k)
                    break;
                temp.push_back(nums[j]);
                m[temp]++;
            }
        }
        return m.size();
    }
};