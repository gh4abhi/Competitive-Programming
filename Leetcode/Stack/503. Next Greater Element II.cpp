// Problem Link - https://leetcode.com/problems/next-greater-element-ii/

#define ll int

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        ll n = nums.size();
        stack<ll> st;
        vector<ll> ans(nums.size());
        for(ll i=2*n-1;i>=0;i--)
        {
            while(st.size() and st.top()<=nums[i%n])
                st.pop();
            if(i<n){   
            if(st.size())
                ans[i%n] = st.top();
            else
                ans[i%n] = -1;
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};