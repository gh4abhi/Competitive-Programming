// Problem Link - https://leetcode.com/problems/kth-largest-element-in-a-stream/

#define ll int

class KthLargest {
public:
    ll kth;
    vector<ll> vect;
    priority_queue <ll, vector<ll>, greater<ll> > pq;
    KthLargest(int k, vector<int>& nums) {
        vect = nums;
        kth = k;
        pq = priority_queue <ll, vector<ll>, greater<ll> > (vect.begin(),vect.end());
        while(pq.size()>kth)
            pq.pop();
    }
    
    int add(int val) {
     vect.push_back(val);
        pq.push(val);
        while(pq.size()>kth)
            pq.pop();
    return pq.top();
    }
};