// Problem Link - https://leetcode.com/contest/weekly-contest-296/problems/partition-array-such-that-maximum-difference-is-k/

#define ll int

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        ll count = 1;
        ll mini = nums[0];
        ll maxi = nums[0];
        for(ll i=0;i<nums.size();i++)
        {
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
            if(maxi-mini>k)
            {
                mini = nums[i];
                maxi = nums[i];
                count++;
            }
        }
        return count;
    }
};