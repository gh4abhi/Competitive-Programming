// Problem Link - https://leetcode.com/problems/sliding-window-maximum/

#define ll int

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<ll> dq;
        vector<ll> ans;
        for(ll i=0;i<nums.size();i++)
        {
            if(dq.size() and dq.front()==i-k)
                dq.pop_front();
            while(dq.size() and nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) 
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};