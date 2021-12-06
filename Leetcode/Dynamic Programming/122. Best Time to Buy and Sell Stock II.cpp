// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#define ll int
class Solution {
public:
    int maxProfit(vector<int>& prices) {
     ll overAllProfit = 0;
        for(ll i=1; i<prices.size();i++)
        {
            if(prices[i-1]<prices[i])
            {
                overAllProfit += prices[i] - prices[i-1];
            }
        }
        return overAllProfit;
    }
};
