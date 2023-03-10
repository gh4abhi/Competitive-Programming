// Problem Link - https://leetcode.com/problems/maximum-product-after-k-increments/

#define ll long long
#define MOD 1000000007

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int> > pq;
        for(auto i:nums)
            pq.push(i);
        while(k--)
        {
            ll val = pq.top();
            pq.pop();
            pq.push(val + 1);
        }
        ll pro = 1;
        while(pq.size())
        {
            pro = ((pro%MOD) * (pq.top()%MOD))%MOD;
            pro = pro%MOD;
            pq.pop();
        }
        return (int)pro%MOD;
    }
};