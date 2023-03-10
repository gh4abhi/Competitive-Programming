// Problem Link - https://www.codingninjas.com/codestudio/problems/980226?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
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