// Problem Link - https://leetcode.com/contest/biweekly-contest-74/problems/minimum-operations-to-halve-array-sum/

#define ll int

class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0;
        double half = 0;
        priority_queue<double> pq;
        for(auto i:nums)
        {    
            sum+=i;
            pq.push(i);
        }
         half = sum/(2.0);
        double nextSum = 0;
        ll count = 0;
        while(1)
        {
            count++;
            double cur = pq.top();
            pq.pop();
            nextSum += cur/2;
            pq.push(cur/2);
            if(nextSum>=half)
                return count;
        }
        return 0;
    }
};