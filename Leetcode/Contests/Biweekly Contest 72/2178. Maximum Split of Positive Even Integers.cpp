// Problem Link - https://leetcode.com/contest/biweekly-contest-72/problems/maximum-split-of-positive-even-integers/

#define ll long long

class Solution {
public:
    
    vector<ll> ans;
    
   
    
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<ll> vect;
        if(finalSum&1)
             return ans;
        ll a = 2;
        while(1)
        {
            if(finalSum==0)
                return ans;
            if(finalSum<a)
            {
                ans[ans.size()-1]+=finalSum;
                return ans;
            }
            ans.push_back(a);
            finalSum-=a;
            a+=2;
        }
    }
};