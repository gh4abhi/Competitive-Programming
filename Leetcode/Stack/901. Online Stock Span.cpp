// Problem Link - https://leetcode.com/problems/online-stock-span/

#define ll int

class StockSpanner {
public:
    stack<pair<ll,ll>> st;
    ll k;
    StockSpanner() {
        st.push({INT_MAX,-1});
        k = 0;
    }
    
    int next(int price) {
      while(st.top().first<=price)
        st.pop();
      ll ans = k-st.top().second;
      st.push({price,k++});
      return (ans);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */