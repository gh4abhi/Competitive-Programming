// Problem Link - https://leetcode.com/problems/find-median-from-data-stream/

#define ll int

class MedianFinder {
public:
    priority_queue<ll> maxHeap;
    priority_queue<ll,vector<ll>,greater<ll>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ll lsize = maxHeap.size();
        ll rsize = minHeap.size();
        if(lsize==0)
            maxHeap.push(num);
        else if(lsize==rsize)
        {
            if(num<minHeap.top())
                maxHeap.push(num);
            else
            {
                ll temp = minHeap.top();
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(temp);
            }
        }
        else
        {
            if(minHeap.size()==0)
            {
                if(num>maxHeap.top())
                    minHeap.push(num);
                else
                {
                ll temp = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(temp);                    
                }
            }
            else if(num>=minHeap.top())
                minHeap.push(num);
            else
            {
                if(num<maxHeap.top())
                {
                    ll temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(temp);
                }
                else
                    minHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        ll l = maxHeap.size();
        ll r = minHeap.size();
        if((l+r)&1)
            return maxHeap.top();
        return ((maxHeap.top() + minHeap.top())*1.0)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */