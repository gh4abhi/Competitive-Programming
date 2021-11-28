// Problem Link - https://leetcode.com/contest/biweekly-contest-66/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/

#define ll int

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        ll rI = startPos[0];
        ll eI = startPos[1];
        ll rE = homePos[0];
        ll eE = homePos[1];
        ll costs = 0;
        while(rI!=rE)
        {
            if(rI<rE)
            {
                rI++;
                costs+= rowCosts[rI];
                cout<<rowCosts[rI]<<endl;
            }
            else if(rI>rE)
            {
                rI--;
                costs+= rowCosts[rI];
                cout<<rowCosts[rI]<<endl;
            }
        }
        while(eI!=eE)
        {
            if(eI<eE)
            {
                eI++;
                costs+= colCosts[eI];
                cout<<colCosts[eI]<<endl;

            }
            else if(eI>eE)
            {
                eI--;
                costs+= colCosts[eI];
                cout<<colCosts[eI]<<endl;
            }
        }
        return costs;
    }
};
