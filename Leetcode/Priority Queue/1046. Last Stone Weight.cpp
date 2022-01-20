// Problem Link - https://leetcode.com/problems/last-stone-weight/

#define ll int

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
     priority_queue<ll> pq;
        
        for(auto i:stones)
        {
            pq.push(i);
        }
        while(pq.size()>1)
        {
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            pq.push(max(a,b)-min(a,b));
        }
        if(pq.size()==0)
            return 0;
        return pq.top();
    }
};
