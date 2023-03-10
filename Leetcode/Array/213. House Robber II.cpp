// Problem Link - https://leetcode.com/problems/house-robber-ii/

#define ll int

class Solution {
public:
    int rob(vector<int>& nums) {
        ll robI = nums[0], nrobI = 0, robS = 0, nrobS = 0;
        ll n = nums.size();
        for(ll i=1;i<n-1;i++)
        {
            ll currentRob = nums[i] + nrobI;
            ll currentNRob = max(robI,nrobI);
            
            robI = currentRob;
            nrobI = currentNRob;
        }
        
        if(n==1)
        {
            return max(robI,nrobI);
        }
        
        robS = nums[1];
        for(ll i=2;i<n;i++)
        {
            ll currentRob = nums[i] + nrobS;
            ll currentNRob = max(robS,nrobS);
            
            robS = currentRob;
            nrobS = currentNRob;
        }
        return max(robI,max(nrobI,max(robS,nrobS)));
    }
};
