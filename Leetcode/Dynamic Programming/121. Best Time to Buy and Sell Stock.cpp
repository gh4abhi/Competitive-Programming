// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#define ll int

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       ll mini = INT_MAX;
        ll ans = INT_MIN;
        for(ll i=0;i<prices.size();i++)
        {
            if(prices[i]<mini)
            {
                mini = prices[i];
            }
            else
            {
                ans = max(ans,prices[i]-mini);
            }
        }
        if(ans==INT_MIN)
            return 0;
        return ans;
    }
};
