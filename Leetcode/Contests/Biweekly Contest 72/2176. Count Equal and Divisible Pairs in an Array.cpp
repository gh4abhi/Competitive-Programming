// Problem Link - https://leetcode.com/contest/biweekly-contest-72/problems/count-equal-and-divisible-pairs-in-an-array/

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        ll count = 0;
        for(ll i=0;i<nums.size();i++)
        {
            for(ll j = i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j] and (i*j)%k==0)
                    count++;
            }
        }
        return count;
    }
};