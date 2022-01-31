// Problem Link - https://leetcode.com/problems/richest-customer-wealth/

#define ll int

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        ll maxi = INT_MIN;
        for(auto i:accounts)
        {
            ll sum = 0;
            for(auto j:i)
            {
                sum+=j;
            }
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};
