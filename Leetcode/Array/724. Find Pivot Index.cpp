// Problem Link - https://leetcode.com/problems/find-pivot-index/

#define ll long long

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        ll n = nums.size();
        if(n==1)
            return 0;
        ll sum = nums[0], op = 0;
        for(ll i=1;i<n;i++)
            sum+=nums[i];
        for(ll i=0;i<n;i++)
        {
            op += nums[i];
            if(op-nums[i]==sum-op)
                return i;
        }
        return -1;
    }
};