// Problem Link - https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

#define ll int

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        ll od=0,ev=0;
        for(ll i=0;i<position.size();i++)
        {
            if(position[i]&1)
            {
                od++;
            }
            else
            {
                ev++;
            }
        }
        
        return min(od,ev);
    }
};
