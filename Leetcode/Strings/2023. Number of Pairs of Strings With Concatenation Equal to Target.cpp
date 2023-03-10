// Problem Link - https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/

#define ll int

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        ll count = 0;
        for(ll i=0;i<nums.size();i++)
        {
            for(ll j= 0; j<nums.size();j++)
            {
                if(i==j)
                    continue;
                string temp = "";
                temp += nums[i] + nums[j];
                if(temp==target)
                    count++;
            }
        }
        return count;
    }
};