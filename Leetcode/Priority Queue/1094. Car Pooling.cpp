// Problem Link - https://leetcode.com/problems/car-pooling/

#define ll int

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[](vector<ll> &a, vector<ll> &b){
            return a[1]<b[1];
        });      
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        ll op = 0;
        for(auto i:trips)
        {
            while(pq.size() and pq.top().first<=i[1])
                op -= pq.top().second, pq.pop();
            op += i[0];
            if(op>capacity)
                return false;
            pq.push({i[2],i[0]});
        }
        return true;
    }
};