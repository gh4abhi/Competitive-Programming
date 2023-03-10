// Problem Link - https://leetcode.com/problems/running-sum-of-1d-array/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> vect;
        int sum = 0;
        for(auto i:nums)
        {
            vect.push_back(sum+i);
            sum+=i;
        }
        
        return vect;
    }
};
