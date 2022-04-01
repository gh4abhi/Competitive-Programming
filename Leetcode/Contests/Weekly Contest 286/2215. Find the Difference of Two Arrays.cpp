// Problem Link - https://leetcode.com/contest/weekly-contest-286/problems/find-the-difference-of-two-arrays/

#define ll int

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<ll,ll> m1,m2;
        for(auto i:nums1)
            m1[i]++;
        for(auto i:nums2)
            m2[i]++;
        vector<vector<ll>> ans;
        vector<ll> a,b;
        map<ll,ll> a1,b1;
        for(auto i:nums1)
        {
            if(m2.count(i)==0 and a1.count(i)==0)
            {
                a.push_back(i);
                a1[i]++;
            }
        }
        for(auto i:nums2)
        {
            if(m1.count(i)==0 and b1.count(i)==0)
            {
                b.push_back(i);
                b1[i]++;
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};