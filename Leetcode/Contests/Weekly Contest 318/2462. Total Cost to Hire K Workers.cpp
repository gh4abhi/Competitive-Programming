// Problem Link - https://leetcode.com/contest/weekly-contest-318/problems/total-cost-to-hire-k-workers/

#define ll long long

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        priority_queue<ll,vector<ll>,greater<ll>> pq, op;
        ll n = costs.size();
        ll start = c, end = n-c-1;
        for(ll i=0;i<min(n,(ll)c);i++)
            pq.push(costs[i]);
        for(ll i=n-1;i>max({n-(ll)c-1,(ll)c-1,0ll});i--)
            op.push(costs[i]);
        ll ans = 0;
        while(k--)
        {
            ll a = INT_MAX, b = INT_MAX;
            if(pq.size())
                a = pq.top();
            if(op.size())
                b = op.top();
            if(a<=b)
            {
                pq.pop();
                if(start<=end)
                    pq.push(costs[start++]);
            }
            else
            {
                op.pop();
                if(start<=end)
                    op.push(costs[end--]);
            }
            ans += min(a,b);
        }
        return ans;
    }
};
