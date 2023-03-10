// Problem Link - https://leetcode.com/problems/jump-game-ii/

#define ll int
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        ll destination = nums[0];
        ll steps = nums[0];
        ll jumps = 1;
        for(ll i=1;i<nums.size();i++)
        {
            destination = max(destination,nums[i]+i);
            if(i==nums.size()-1)
                return jumps;
            steps--;
            if(steps==0)
            {
                if(i>=destination)
                    return -1;
                jumps++;
                steps = destination - i;
            }
        }
        return -1;
    }
};