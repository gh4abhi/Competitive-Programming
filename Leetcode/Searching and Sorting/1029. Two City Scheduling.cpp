// Problem Link - https://leetcode.com/problems/two-city-scheduling/

#define ll int
class Solution {
public:
ll ans = INT_MAX;
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](const vector<ll>&a, vector<ll>&b){
            return abs(a[0]-a[1])>abs(b[0]-b[1]);
        });
        
             ll x1 = costs.size()/2;
        ll x2 = x1;
             ll sum = 0;
             for(auto i:costs)
             {
                 if((i[0]<i[1] and x1) or x2==0)
                 {
                     x1--;
                     sum+=i[0];
                 }
                 else  {
                     x2--;
                     sum += i[1];
                 }
             }
             return sum;
    }
};