// Problem Link - https://leetcode.com/problems/maximum-ice-cream-bars/

#define ll int

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        ll ans = 0;
        for(auto i:costs)
            if(i<=coins)
                coins-=i,ans++;
        return ans;
    }
};