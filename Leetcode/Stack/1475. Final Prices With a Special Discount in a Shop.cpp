// Problem Link - https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

#define ll int

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        ll n = prices.size();
        vector<ll> ans(n,-1);
        stack<ll> st;
        for(ll i=n-1;i>=0;i--)
        {
            if(st.size()==0)
            {
                st.push(prices[i]);
                ans[i] = prices[i];
                continue;
            }
            while(st.size() and st.top()>prices[i])
                st.pop();
            if(st.size())
                ans[i] = prices[i] - st.top();
            else
                ans[i] = prices[i];
            st.push(prices[i]);
        }
        return ans;
    }
};