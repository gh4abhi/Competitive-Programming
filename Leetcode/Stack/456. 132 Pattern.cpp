// Problem Link - https://leetcode.com/problems/132-pattern/

#define ll int

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        ll n = nums.size();
        ll preMin[n];
        ll mini = nums[0];
        for(ll i=0;i<n;i++)
            mini = min(mini,nums[i]), preMin[i] = mini;
        stack<ll> st;
        for(ll j=nums.size()-1;j>=0;j--)
        {
            while(st.size() and st.top()<=preMin[j])
                st.pop();
           if(st.size() and nums[j]>st.top())
                return true;
            st.push(nums[j]);
        }
        return false;
    }
};