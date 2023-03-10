// Problem Link - https://leetcode.com/problems/house-robber/

#define ll int

class Solution {
public:
    int rob(vector<int>& nums) {
     ll rob=0, nrob=0;
        rob = nums[0];
        for(ll i=1;i<nums.size();i++)
        {
            ll currentRob = nums[i] + nrob;
            ll currentNRob = max(nrob,rob);
            
            nrob = currentNRob;
            rob = currentRob;
        }
        
        return max(rob,nrob);
    }
};
