// Problem Link - https://leetcode.com/problems/next-greater-element-i/

#define ll int

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<ll,ll> m;
        stack<ll> st;
        st.push(-1);
        for(ll i=nums2.size()-1;i>=0;i--)
        {
            while(st.top()<nums2[i] and st.size()>1)
                st.pop();
            m[i] = st.top();
            st.push(nums2[i]);
        }
        vector<ll> ans;
        for(ll i=0;i<nums1.size();i++)
        {
            for(ll j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                    ans.push_back(m[j]);
            }
        }
        return ans;
    }
};