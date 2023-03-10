// Problem Link - https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

#define ll int
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        ll sum = 0;
        ll mini = INT_MAX;
        for(ll i=0; i<nums.size();i++)
        {
            sum += nums[i];
            mini = min(sum,mini);
        }
        
        if(mini<0)
        {
            return (abs(mini)+1);    
        }
        else 
        {
            return 1;
        }
            
    }
};
